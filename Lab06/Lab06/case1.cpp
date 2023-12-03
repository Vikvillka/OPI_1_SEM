#include"case1.h"
#include<iostream>
using namespace std;
int case1()
{
	char c;
    int X, y;
	int n;
	setlocale(LC_ALL, "Russian");
	cout << "Введите сколько будет повторений ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "Введите символ" << endl;
		cin >> c;
		if (c > 0x40 && c < 0x5B) 
		{
			X = int(c) + 32;
			y = char(X) - int(c);
		}
		else if (c > 0x60 && c < 0x7B) 
		{
			X = int(c) - 32;
			y = int(c) - char(X);
		}
		else 
		{ 
			cout << "ERROR" << endl; break; 
		}
		cout << "Код символа " << c << " В ASCII = " << hex << int(c) << ", код символа " << char(X) << " - " << hex << X << " Разница между значениями в шестнадцатеричной системе счисления = " << y << endl;
	}
return 0;
}