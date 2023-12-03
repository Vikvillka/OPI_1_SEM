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
	cout << "�������� ��������" << endl;
	cout << "1 � ����������� ������� �������� ����� � ASCII ����� ���������� �������� � ��������� � �������� ���������" << endl;
	cout << "2 � ����������� ������� �������� ����� � Windows-1251 ����� �������� �������� � ��������� � �������� ���������" << endl;
	cout << "3 � ����� � ������� ���� �������, ���������������� ��������� �����" << endl;
	cout << "4 - ����� �� ���������" << endl;
	cin >> a;
	switch (a) 
	{
	case 1: 
	{
		cout << "������� ������ " << endl;
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
		cout << "��� ������� " << symbol << " � ASCII = " << hex << int(symbol) << ", ��� ������� " << char(letter_en) << " - " << hex << letter_en << " ������� ����� ���������� � ����������������� ������� ��������� = " << int(difference) << endl; break;
	}
	case 2: 
	{
		cout << "������� ������ " << endl;
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
		cout << "��� ������� " << symbol << " � Windows-1251 = " << hex << int(symbol_ru) << ", ��� ������� " << char(letter_ru) << " - " << hex << int(letter_ru) << " ������� ����� ���������� � ����������������� ������� ��������� ="<< int(difference) << endl; break;
	}
	case 3: 
	{
		cout << "������� ������ " << endl;
		cin >> symbol;
		if (int(symbol) > 0x2A && int(symbol) < 0x3A) 
		{
			number = symbol;
			cout<<"��� ������� " << number << " � ����������������� ������� ��������� = " << hex << int(number);
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