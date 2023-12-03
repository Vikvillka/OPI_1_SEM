#include <iostream>

using namespace std;

int WSymb(char n) {
	cout << (- 1 * (int)n) - (-1 * (int)toupper(n)) << endl;
	cout << "Вы ввели русский символ" << endl;

	return 0;
}