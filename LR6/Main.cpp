#include "CombiPlacementInterraction.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13
#define KEY_ESC 27
#define KEY_BACKSPACE 8

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void GoToXY(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}

void ConsoleCursorVisible(bool show, short size)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show;
	structCursorInfo.dwSize = size;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleTitle(L"Размещения и сочетания");
	ConsoleCursorVisible(false, 100);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);

	CombiPlacementInterraction test;

	int active_menu = 0;
	int keyInput;
	bool exitProg = false;

	while (!exitProg)
	{
		int x = 40, y = 12;
		GoToXY(x, y);

		vector<string> menu =
		{
			"Лексикографическая генерация сочетаний",
			"	Генерация размещений",
			"		Выход"
		};

		for (int i = 0; i < menu.size(); i++)
		{
			if (i == active_menu)
			{
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else
			{
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			}

			GoToXY(x, y++);
			cout << menu[i] << endl;
		}

		keyInput = _getch();
		switch (keyInput)
		{
			case KEY_ESC:
				exit(0);

			case KEY_UP:
			{
				if (active_menu > 0)
				{
					active_menu--;
				}
			}
			break;

			case KEY_DOWN:
			{
				if (active_menu < menu.size() - 1)
				{
					active_menu++;
				}
			}
			break;

			case KEY_ENTER:
			{
				switch (active_menu)
				{
					case 0:
					{
						system("cls");

						int n, k;
						cout << "Введите количество элементов в множестве" << endl;
						cin >> n;
						cout << "Введите количество элементов в сочетании" << endl;
						cin >> k;

						while (k > n)
						{
							system("cls");
							cout << "Неверные данные" << endl;
							cout << "Введите количество элементов в множестве" << endl;
							cin >> n;
							cout << "Введите количество элементов в сочетании" << endl;
							cin >> k;
						}

						system("cls");

						vector<vector<int>> allCombs;
						test.genComb(allCombs, n, k);

						cout << "Лексикографический порядок " << k << "-сочетаний из " << n << "-элементов:" << endl;
						for (auto row : allCombs)
						{
							if (row.empty())
							{
								cout << "<пустое множество>" << endl;
							}
							else
							{
								cout << ">";
								for (auto el : row)
								{
									cout << el << " ";
								}
								cout << endl;
							}
						}


						test.printQuit();
					}
					break;

					case 1:
					{
						system("cls");

						int n, k;
						cout << "Введите количество элементов в множестве" << endl;
						cin >> n;
						cout << "Введите количество элементов в размещении" << endl;
						cin >> k;

						while (k > n)
						{
							system("cls");
							cout << "Неверные данные" << endl;
							cout << "Введите количество элементов в множестве" << endl;
							cin >> n;
							cout << "Введите количество элементов в сочетании" << endl;
							cin >> k;
						}

						system("cls");

						vector<vector<int>> allPlaces;
						test.genPlaces(allPlaces, n, k);

						cout << "Все " << k << "-размещения из " << n << "-элементов:" << endl;
						for (auto row : allPlaces)
						{
							if (row.empty())
							{
								cout << "<пустое множество>" << endl;
							}
							else
							{
								cout << ">";
								for (auto el : row)
								{
									cout << el << " ";
								}
								cout << endl;
							}
						}

						test.printQuit();
					}
					break;

					case 2:
					{
						exitProg = true;
					}
					break;
				}
			}
			break;
		}
	}

}