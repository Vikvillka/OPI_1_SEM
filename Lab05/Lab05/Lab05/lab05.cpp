#include <iostream>
#include <windows.h>
using namespace std;

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a;
	char symbol, number;
	int letter_en, letter_ru, symbol_ru, difference;
	cout << "Выберите действие" << endl;
	cout << "1 – определение разницы значений кодов в ASCII буквы латинского алфавита в прописном и строчном написании" << endl;
	cout << "2 – определение разницы значений кодов в Windows-1251 буквы русского алфавита в прописном и строчном написании" << endl;
	cout << "3 – вывод в консоль кода символа, соответствующего введенной цифре" << endl;
	cout << "4 - выход из программы" << endl;
	cin >> a;
	switch (a) 
	{
	case 1: 
	{
		cout << "Введите символ " << endl;
		cin >> symbol;
		if (symbol >0x40 && symbol < 0x5B) 
		{
			letter_en = int(symbol) + 32;
			difference = char(letter_en) - int(symbol);
		}
		else if (symbol > 0x60 && symbol < 0x7B) 
		{
			letter_en = int(symbol) - 32;
			difference = int(symbol) - char(letter_en);
		}
		else 
		{ 
			cout << "ERROR" << endl; break; 
		}
		cout << "Код символа " << symbol << " В ASCII = " << hex << int(symbol) << ", код символа " << char(letter_en) << " - " << hex << letter_en << " Разница между значениями в шестнадцатеричной системе счисления = " << int(difference) << endl; break;
	}
	case 2: 
	{
		cout << "Введите символ " << endl;
		cin >> symbol;
		symbol_ru = int(symbol) + 256;
		if (symbol_ru > 191 && symbol_ru < 224) 
		{
			letter_ru = symbol_ru + 32;
			difference = char(letter_ru) - int(symbol);
		}
		else if (symbol_ru > 0xDF && symbol_ru <= 0xFF) 
		{
			letter_ru = symbol_ru - 32;
			difference = int(symbol) - char(letter_ru);
		}
		else 
		{ 
			cout << "ERROR" << endl; break; 
		}
		cout << "Код символа " << symbol << " В Windows-1251 = " << hex << int(symbol_ru) << ", код символа " << char(letter_ru) << " - " << hex << int(letter_ru) << " Разница между значениями в шестнадцатеричной системе счисления ="<< int(difference) << endl; break;
	}
	case 3: 
	{
		cout << "Введите символ " << endl;
		cin >> symbol;
		if (int(symbol) > 0x2A && int(symbol) < 0x3A) 
		{
			number = symbol;
			cout<<"Код символа " << number << " в шестнадцатеричной системе счисления = " << hex << int(number);
		}
		else cout << "ERROR"; break;
	}
	case 4: 
	{
		break;
	}
	default: break;
	}
	return 0;
}