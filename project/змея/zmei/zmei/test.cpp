#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <cstdlib>

#define ESCAPE 27
#define ENTER 13

using namespace std;

bool gameOver;
const int width = 80;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void snake();
void turtle();

//////////////////////////// �������� ������� ���� /////////////
//���������� ������
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); //��������� ����������� �������
void GoToXY(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x, y }); // ��������� ������ � ����� x,y
}

//������ ������
void ConsoleCursorVisible(bool show, short size)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show; // �������� ��������� �������
	structCursorInfo.dwSize = size; // �������� ������ �������
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}
void menu() {
	GoToXY(50, 10);
	ConsoleCursorVisible(false, 100);
	string Menu[] = { "������ � Snake", "������ � Turtle", "�����" };
	int active = 0;

	char ch;
	while (true)
	{
		//logo
		SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		GoToXY(20, 1);
		cout << " _____  _____  __ __  _____  __       _____  __  _____  _____  _____  _____" << endl;
		GoToXY(20, 2);
		cout << "| __  ||     ||  |  ||  _  ||  |     |  |  ||  ||  _  ||   __|| __  ||   __|" << endl;
		GoToXY(20, 3);
		cout << "|    -||  |  ||_   _||     ||  |__   |  |  ||  ||   __||   __||    -||__   |" << endl;
		GoToXY(20, 4);
		cout << "|__|__||_____|  |_|  |__|__||_____|   \\___/ |__||__|   |_____||__|__||_____|";

		int x = 50, y = 13;
		GoToXY(x, y);
		for (int i = 0; i < size(Menu); i++)
		{
			if (i == active) SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			else SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			GoToXY(x, y++);
			cout << Menu[i] << endl;
		}
		ch = _getch();
		if (ch == -32) ch = _getch(); // ����������� ���������
		switch (ch)
		{
		case ESCAPE: // escape
			exit(0);
		case 'w':
		case 'W':
		case '�':
		case '�':
			if (active > 0) {
				active--;
			}
			break;
		case 's':
		case 'S':
		case '�':
		case '�':
			if (active < size(Menu) - 1) {
				active++;
			}
			break;
		case ENTER:
			switch (active)
			{
			case 0:
				system("CLS");
				GoToXY(x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				snake();
				system("CLS");
				break;
			case 1:
				system("CLS");
				GoToXY(x, y);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				turtle();
				system("CLS");
				break;
			case 2:
				system("cls");
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				GoToXY(40, 1);
				cout << "                             ,---." << endl;
				GoToXY(40, 2);
				cout << " ,-----.                     |   |" << endl;
				GoToXY(40, 3);
				cout << " |  |) /_  ,--. ,--.  ,---.  |  .'" << endl;
				GoToXY(40, 4);
				cout << " |  .-.  \\  \\  '  /  | .-. : |  | " << endl;
				GoToXY(40, 5);
				cout << " |  '--' /   \\   '   \\   --. `--' " << endl;
				GoToXY(40, 6);
				cout << " `------'  .-'  /     `----' .--. " << endl;
				GoToXY(40, 7);
				cout << "           `---'             '--' " << endl;

				exit(0);
			}
			break;
		default:
			break;
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//��������� ����������� ����
	SetConsoleTitle(L"Game Launcher �Royal Vipers - 2022");

	menu();

	//system("pause");
}

void SetUp()
{
	gameOver = false;
	dir = STOP;

	x = width / 2 - 1;
	y = height / 2 - 1;
	fruitX = rand() % width;
	fruitY = rand() % height;

	score = 0;
}

void Draw()
{
	system("cls");

	for (int i = 0; i < width + 1; i++)
	{
		cout << "_";
	}
	cout << endl;


	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width - 1)
			{
				cout << "|";
			}
			if (j == x && i == y)
			{
				cout << "@";
			}
			else if (i == fruitY && j == fruitX)
			{
				cout << "O";
			}
			else {
				bool paint = false;
				for (int k = 0; k < nTail; k++)
				{
					if (i == tailY[k] && j == tailX[k])
					{
						cout << "o";
						paint = true;
					}
				}
				if (!paint)
				{
					cout << " ";
				}

			}
		}

		cout << endl;
	}

	for (int i = 0; i < width + 1; i++)
	{
		cout << "_";
	}

	cout << endl;

	cout << "Score: " << score << endl;

	cout << endl;

	cout << "����������: "  << endl;
	cout << "W - ����� "  << endl;
	cout << "S - ���� " << endl;
	cout << "D - ������ " << endl;
	cout << "A - ����� " << endl;
	cout << "�sc - �����";
}

void Input()
{

	if (_kbhit())
	{
		char ch = _getch();
		if (ch == -32) ch = _getch();
		switch (ch)
		{
		case 'w':
		case 'W':
		case '�':
		case '�':
			dir = UP; break;

		case 'a':
		case 'A':
		case '�':
		case '�':
			dir = LEFT; break;

		case 's':
		case 'S':
		case '�':
		case '�':
			dir = DOWN; break;

		case 'd':
		case 'D':
		case '�':
		case '�':
			dir = RIGHT; break;

		case ESCAPE:
		{
			gameOver = true;
			break;
		}
		}
	}
}

void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}



	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}

	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}

	if (x < 0)
	{
		x = width - 2;
	}
	else if (x >= width - 1)
	{
		x = 0;
	}

	if (y < 0)
	{
		y = height - 1;
	}
	else if (y >= height)
	{
		y = 0;
	}


	for (int i = 0; i < nTail; i++)
	{
		if (x == tailX[i] && y == tailY[i])
		{
			gameOver = true;
			nTail = 0;
		}
	}

	if (gameOver)
	{
		system("cls");
		GoToXY(50, 10);
		ConsoleCursorVisible(false, 100);
		SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		GoToXY(20, 1);
		cout << "  ____" << endl;
		GoToXY(20, 2);
		cout << " /  __\\  _____  _______   _____    _____  _____  ____  _____" << endl;
		GoToXY(20, 3);
		cout << "|  |___ |  _  ||       \\ |   __|  |     ||  |  ||  __|| __  |" << endl;
		GoToXY(20, 4);
		cout << "|   |  ||     ||  |  |  ||   __|  |  |  ||  |  ||  __||    -|" << endl;
		GoToXY(20, 5);
		cout << " \\____/ |__|__||__|__|__||_____|  |_____| \\___/ |____||__|__|" << endl;
		GoToXY(21, 6);
		cout << "������� ����� �������, ����� ������ �������... (esc - �����)" << endl;
	}

if (score==1000)
{
		system("cls");
		GoToXY(50, 10);
		ConsoleCursorVisible(false, 100);
		SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		GoToXY(20, 1);
		cout << " _   _                                          _" << endl;
		GoToXY(20, 2);
		cout << "| |_| | _____  _____    __      __  __  ____   | |" << endl;
		GoToXY(20, 3);
		cout << " \\   / |     ||  |  |  |  | __ |  ||  ||    \\  |_|" << endl;
		GoToXY(20, 4);
		cout << "  | |  |  |  ||  |  |  |  |/  \\|  ||  ||  |  |  _" << endl;
		GoToXY(20, 5);
		cout << "  |_|  |_____| \\___/    \\___/\\___/ |__||__|__| |_| " << endl;
		GoToXY(21, 7);
		cout << "������� ����� �������, ����� ������ �������... (esc - �����)" << endl;
		gameOver = true;
		nTail = 0;
	}		
}
//�������� ������� ������
void snake() {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool restart = true;
	while (restart)
	{
		SetUp();
		while (!gameOver)
		{
			Draw();
			Input();
			Logic();
			Sleep(20); //���� ������!
		}
		if (_getch() == ESCAPE)
		{
			break;
		}
	}
}

/////////////////////////// �������� ///////////////////////////
#define wieght 80
#define height 20
#define player '�'
#define borderY '|'
#define borderX '_'
bool gameEnd = false;

void DrawT(char field[height][wieght])
{
	system("cls");
	for (int i = 0; i < height; i++)
	{
		cout << field[i] << endl;
	}
	cout << endl;
	
	cout << "����������: " << endl;
	cout << endl;
	cout << "Space - ��������/������� " << endl;
	cout << "W - ����� " << endl;
	cout << "S - ���� " << endl;
	cout << "D - ������ " << endl;
	cout << "A - ����� " << endl;
	cout << "�sc - �����";
}

void CreateField(char field[height][wieght])
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < wieght; j++)
			if (i == 0 || i == height - 1)
				field[i][j] = borderX;
			else if (j == wieght - 2 || j == 0)
				field[i][j] = borderY;
			else
				field[i][j] = ' ';
		field[i][wieght - 1] = '\0';
	}
}


void moveKEYS(char field[height][wieght], char playerAction, int playerCoords[2], int& paint) {
	int lastcoords[2];
	lastcoords[0] = playerCoords[0];
	lastcoords[1] = playerCoords[1];
	if (playerAction == '�' || playerAction == 'w')
	{
		playerCoords[0]--;
	}
	else if (playerAction == '�' || playerAction == 's')
	{
		playerCoords[0]++;
	}
	else if (playerAction == '�' || playerAction == 'a')
	{
		playerCoords[1]--;
	}
	else if (playerAction == '�' || playerAction == 'd')
	{
		playerCoords[1]++;
	}
	else if (playerAction == '�' || playerAction == 'e')
	{
		paint++;
	}
	else if (playerAction == ESCAPE)
	{
		gameEnd = true;
	}

	if (field[playerCoords[0]][playerCoords[1]] == ' ' || field[playerCoords[0]][playerCoords[1]] == '*')
	{
		if (paint % 2 == 0)
			field[lastcoords[0]][lastcoords[1]] = ' ';
		else
			field[lastcoords[0]][lastcoords[1]] = '*';
	}

	else {
		playerCoords[0] = lastcoords[0];
		playerCoords[1] = lastcoords[1];
	}

}
///////////�������� ������� ��������/////////
void turtle() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(0));
	char field[height][wieght];
	int playerCoords[2] = { height / 2, wieght / 2 };
	char playerAction;
	int paint = 0;
	CreateField(field);
	while (true)
	{
		field[playerCoords[0]][playerCoords[1]] = player;
		DrawT(field);
		Sleep(0);
		playerAction = _getch();
		moveKEYS(field, playerAction, playerCoords, paint);
		if (gameEnd == true) {
			break;
		}
	}
}