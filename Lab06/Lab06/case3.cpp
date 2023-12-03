#include"case3.h"
#include<iostream>
using namespace std;

int case3()
{
	char c;
	float s;
	int n;
	setlocale(LC_ALL, "Russian");
	cout << "Введите сколько будет повторений ";
	cin >> n;
	cout << "Введите символы"<< endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> c;
		if (int(c) > 0x2A && int(c) < 0x3A) 
		{
			s = c;
			cout << "Код символа " << hex << int(s) << endl;
		}
		else 
		{
			cout << "ERROR"; break;
		}
	}
return 0;
}