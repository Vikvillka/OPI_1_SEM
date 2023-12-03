#include"case2.h"
#include<iostream>
#include <windows.h>
using namespace std;

int case2()
{
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	int n;
	char c;
	int X, Y, y;
	setlocale(LC_ALL, "Russian");
	cout << "Введите сколько будет повторений ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "Введите символ" << endl;
		cin >> c;
		Y = int(c) + 256;
        if (Y > 0xBF && Y < 0xE0) 
		{
        	X = Y + 32;
        	y = char(X) - int(c);
        }
        else if (Y > 0xDF && Y <= 0xFF) 
		{
        	X = Y - 32;
        	y = int(c) - char(X);
        }
		else 
		{ 
			cout << "ERROR" << endl; break; 
		}
        cout << "Код символа " << c << " В Windows-1251 = " << hex << int(Y) << ", код символа " << char(X) << " - " << hex << int(X) << " Разница между значениями в шестнадцатеричной системе счисления =" << y << endl;
	}
	return 0;
}