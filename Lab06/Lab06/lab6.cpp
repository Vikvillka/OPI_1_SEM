#include <iostream>
#include <Windows.h>

using namespace std;

bool deistv1()
{
    char letter1, letter2, big;
    cout << "Введите большую и маленькую букву латинского алфавита" << endl;
    cin >> letter1 >> letter2;
    if (letter1 >= 'a' && letter1 <= 'z' || letter1 >= 'A' && letter1 <= 'Z')
    {
        if (islower(letter1))
            big = toupper(letter1);
        else
        {
            big = letter1;
            letter1 = tolower(big);
        }
        cout << "разницa значений кодов в ASCII:" << int(letter1) - int(big) << endl;
    }
    else if (letter1 == '$')
        cout << "выход" << endl;
    else
        cout << "error" << endl;
    return letter1 != '$';
}

bool deistv2() {
    char letter1, letter2;
    cout << "Введите маленькую и большую букву русского алфавита" << endl;
    cin >> letter1 >> letter2;
    if (letter1 >= 'а' && letter1 <= 'я')
    {
        letter1 = char(int(letter1) + 256);
        cout << "разницa значений кодов в Windows-1251:" << int(letter1 - letter2) << endl;
    }
    else if (letter1 >= 'А' && letter1 <= 'Я')
    {
        letter2 = char(int(letter1) + 256);
        cout << "разницa значений кодов в Windows-1251:" << int(letter2 - letter1) << endl;
    }
    else
        if (letter1 == '$')
            cout << "выход" << endl;
        else
            cout << "error" << endl;
    return letter1 != '$';
}

bool deistv3()
{
    char s;
    cout << "Ведите любую цифру" << endl;
    cin >> s;
    if (s >= '0' && s <= '9')
        cout << "код цифры:" << int(s) << endl;
    else
        if (s == '$')
            cout << "выход" << endl;
        else
            cout << "error" << endl;
    return s != '$';
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char deistvie;
    do
    {
        cout << "Выберите любое действие" << endl;
        cout << "1 - разница значений кодов большой и маленькой латинских буков в ASCII;" << endl;
        cout << "2 - разница значений кодов большой и маленькой русских буков в Windows-1251;" << endl;
        cout << "3 - вывод кода символа любого числа;" << endl;

        cin >> deistvie;
        if (deistvie == '1')
        {
            cout << "Для выхода введите: $ " << endl;
            while (deistv1())
            {
            }
        }
        else if (deistvie == '2')
        {
            cout << "Для выхода введите: $ " << endl;
            while (deistv2())
            {
            }
        }
        else if (deistvie == '3')
        {
            cout << "Для выхода введите: $ " << endl;
            while (deistv3())
            {
            }
        }
        else if (deistvie >= '4')
            cout << "error" << endl;
    } while (deistvie >= '4');
    return 0;
}