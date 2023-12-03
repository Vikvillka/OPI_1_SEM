#include <iostream>
#include <Windows.h>

using namespace std;

bool deistv1()
{
    char letter1, letter2, big;
    cout << "������� ������� � ��������� ����� ���������� ��������" << endl;
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
        cout << "������a �������� ����� � ASCII:" << int(letter1) - int(big) << endl;
    }
    else if (letter1 == '$')
        cout << "�����" << endl;
    else
        cout << "error" << endl;
    return letter1 != '$';
}

bool deistv2() {
    char letter1, letter2;
    cout << "������� ��������� � ������� ����� �������� ��������" << endl;
    cin >> letter1 >> letter2;
    if (letter1 >= '�' && letter1 <= '�')
    {
        letter1 = char(int(letter1) + 256);
        cout << "������a �������� ����� � Windows-1251:" << int(letter1 - letter2) << endl;
    }
    else if (letter1 >= '�' && letter1 <= '�')
    {
        letter2 = char(int(letter1) + 256);
        cout << "������a �������� ����� � Windows-1251:" << int(letter2 - letter1) << endl;
    }
    else
        if (letter1 == '$')
            cout << "�����" << endl;
        else
            cout << "error" << endl;
    return letter1 != '$';
}

bool deistv3()
{
    char s;
    cout << "������ ����� �����" << endl;
    cin >> s;
    if (s >= '0' && s <= '9')
        cout << "��� �����:" << int(s) << endl;
    else
        if (s == '$')
            cout << "�����" << endl;
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
        cout << "�������� ����� ��������" << endl;
        cout << "1 - ������� �������� ����� ������� � ��������� ��������� ����� � ASCII;" << endl;
        cout << "2 - ������� �������� ����� ������� � ��������� ������� ����� � Windows-1251;" << endl;
        cout << "3 - ����� ���� ������� ������ �����;" << endl;

        cin >> deistvie;
        if (deistvie == '1')
        {
            cout << "��� ������ �������: $ " << endl;
            while (deistv1())
            {
            }
        }
        else if (deistvie == '2')
        {
            cout << "��� ������ �������: $ " << endl;
            while (deistv2())
            {
            }
        }
        else if (deistvie == '3')
        {
            cout << "��� ������ �������: $ " << endl;
            while (deistv3())
            {
            }
        }
        else if (deistvie >= '4')
            cout << "error" << endl;
    } while (deistvie >= '4');
    return 0;
}