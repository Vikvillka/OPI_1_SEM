#include"symbol.h"
#include<iostream>
using namespace std;

int symbol()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "������� ����� ��������:\n1 � ����������� ������� �������� ����� � ASCII ����� ���������� �������� � ��������� � �������� ���������; \n2 � ����������� ������� �������� ����� � Windows - 1251 ����� �������� �������� � ��������� � �������� ���������; \n3 � ����� � ������� ���� �������, ���������������� ��������� �����; \n4 � ����� �� ���������. " << endl;
	cin >> n;
	return n;
}