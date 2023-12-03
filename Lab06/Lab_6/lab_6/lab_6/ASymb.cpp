#include <iostream>

using namespace std;

int ASymb(char n) {
	cout << (int)n - (int)toupper(n) << endl;
	cout << "Вы ввели латинский символ" << endl;

	return 0;
}