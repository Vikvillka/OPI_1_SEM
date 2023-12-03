#include <iostream>
#include "num.h"
#include "WSymb.h"
#include "ASymb.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");

	char symb[1000];
	int n = 0;

	cout << "Введите количество символов" << endl;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> symb[i];

		if ((int)symb[i] > 0x30 && symb[i] < 0x39)
		{
			//ASCII Number
			num(symb[i]);
		}
		else if ((int)symb[i] > 0x41 && symb[i] <= 0x7A) {
			//ASCII Symbol
			ASymb(symb[i]);
		}
		else if ((int)symb[i] > -127 && symb[i] <= -17) {
			//Windows-1251
			WSymb(symb[i]);
		}
		else {
			cout << "Ошибка" << endl;
		}

		cout << "Символ проверен!" << endl << endl;
	}
}