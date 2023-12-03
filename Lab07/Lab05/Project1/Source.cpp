#include <iostream>
using namespace std;
int main()
{

    double y, z, a = 1.055, x = 0.6, n = 6;
    while (n < 16)
    {
        cout << " n =" << n << endl;
        y = cos(pow(x, 2)) * (pow(x, 2)) / abs(x);
        if (y < a * x * n)
        {
            z = abs(y);
        }
        else
        {
            z = sqrt(1 + exp((-1) * y));
        }

        cout << "z=" << z << endl;
        n += 2;
    }

    system("pause");
}