#include <iostream>
#include <windows.h>
using namespace std;

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a;
	char symbol, number;
	int letter_latin, letter_russian, symbol_russian, result;
	int const REGISTER_DIFFERENCE = 32;
	int const CODE_FOR_RUSSIAN = 256;
	char const START_BIG_LATIN_LIMIT = 0x40, END_BIG_LATIN_LIMIT = 0x5B, START_SMALL_LATIN_LIMIT = 0x60, END_SMALL_LATIN_LIMIT = 0x7B;
	int const START_BIG_RUSSIAN_LIMIT = 191, END_BIG_RUSSIAN_LIMIT = 224, START_SMALL_RUSSIAN_LIMIT = 223, END_SMALL_RUSSIAN_LIMIT = 255;
	char const START_NUMBER_LIMIT = 0x2A, END_NUMBER_LIMIT = 0x3A;
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
		if (symbol > START_BIG_LATIN_LIMIT && symbol < END_BIG_LATIN_LIMIT)
		{
			letter_latin = int(symbol) + REGISTER_DIFFERENCE;
			result = char(letter_latin) - int(symbol);
		}
		else if (symbol > START_SMALL_LATIN_LIMIT && symbol < END_SMALL_LATIN_LIMIT)
		{
			letter_latin = int(symbol) - REGISTER_DIFFERENCE;
			result = int(symbol) - char(letter_latin);
		}
		else 
		{ 
			cout << "ERROR" << endl; break; 
		}
		cout << "Код символа " << symbol << " В ASCII = " << hex << int(symbol) << ", код символа " << char(letter_latin) << " - " << hex << letter_latin << " Разница между значениями в шестнадцатеричной системе счисления = " << int(result) << endl; break;
	}
	case 2: 
	{
		cout << "Введите символ " << endl;
		cin >> symbol;
		symbol_russian = int(symbol) + CODE_FOR_RUSSIAN;
		if (symbol_russian > START_BIG_RUSSIAN_LIMIT && symbol_russian < END_BIG_RUSSIAN_LIMIT)
		{
			letter_russian = symbol_russian + REGISTER_DIFFERENCE;
			result = char(letter_russian) - int(symbol);
		}
		else if (symbol_russian > START_SMALL_RUSSIAN_LIMIT && symbol_russian < END_SMALL_RUSSIAN_LIMIT)
		{
			letter_russian = symbol_russian - REGISTER_DIFFERENCE;
			result = int(symbol) - char(letter_russian);
		}
		else 
		{ 
			cout << "ERROR" << endl; break; 
		}
		cout << "Код символа " << symbol << " В Windows-1251 = " << hex << int(symbol_russian) << ", код символа " << char(letter_russian) << " - " << hex << int(letter_russian) << " Разница между значениями в шестнадцатеричной системе счисления ="<< int(result) << endl; break;
	}
	case 3: 
	{
		cout << "Введите символ " << endl;
		cin >> symbol;
		if (int(symbol) > START_NUMBER_LIMIT && int(symbol) < END_NUMBER_LIMIT)
		{
			number = symbol;
			cout<<"Код символа " << number << " в шестнадцатеричной системе счисления = " << hex << int(number);
		}
		else cout << "ERROR";
		break;
	}
	case 4: 
	{
		break;
	}
	default: 
		cout << "ERROR";
		break;
	}
	return 0;
}