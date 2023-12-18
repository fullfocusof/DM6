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
			"Генерация размещений",
			"Генерация сочетания по номеру",
			"Нахождение номера сочетания",
			"Выход"
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

						cin.ignore();
						cin.clear();

						test.printQuit();
					}
					break;

					case 2:
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

						int num;
						cout << "Введите номер сочетания" << endl;
						cin >> num;

						while (num > test.binomCoef(n, k) - 1 || num < 0)
						{
							system("cls");
							cout << "Неверные данные" << endl;
							cout << "Введите номер сочетания" << endl;
							cin >> num;
						}

						system("cls");

						vector<int> comb = test.genCombFromNum(n, k, num);

						cout << "Полученное сочетание" << endl;
						for (auto& el : comb)
						{
							cout << el << " ";
						}

						cin.ignore();
						cin.clear();

						test.printQuit();
					}
					break;

					case 3:
					{
						system("cls");

						int num;
						string input;
						vector<int> tempVar;
						cout << "Введите перестановку, номер которой хотите получить" << endl << "Введите числа через пробел и нажмите Enter" << endl;
						getline(cin, input);

						while (input.empty())
						{
							system("cls");
							cout << "Вы ввели пустое множество" << endl;
							cout << "Введите числа, после ввода последнего нажмите Enter" << endl;
							getline(cin, input);
							cin.clear();
							cin.ignore(10000, '\n');
						}

						istringstream iss(input);
						while (iss >> num)
						{
							tempVar.push_back(num);
						}

						system("cls");

						int n, k = tempVar.size();					
						cout << "Введите количество элементов в множестве" << endl;
						cin >> n;

						while (k > n)
						{
							system("cls");
							cout << "Неверные данные" << endl;
							cout << "Введите количество элементов в множестве" << endl;
							cin >> n;
						}

						vector<vector<int>> checkComb;
						test.genComb(checkComb, n, k);

						vector<int> revTemp = tempVar;
						reverse(revTemp.begin(), revTemp.end());

						if (find(checkComb.begin(), checkComb.end(), revTemp) == checkComb.end())
						{
							system("cls");
							cout << "Данное сочетание не принадлежит " << n << "-множеству" << endl;
							system("pause");
							system("cls");
							cin.clear();
							cin.ignore(10000, '\n');
							break;
						}

						system("cls");

						cout << "Сочетание: ";
						for (auto& el : tempVar)
						{
							cout << el << " ";
						}
						cout << endl;
						cout << "Номер сочетания - " << test.genNumFromComb(tempVar, n);

						cin.clear();
						cin.ignore(10000, '\n');

						test.printQuit();
					}
					break;

					case 4:
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