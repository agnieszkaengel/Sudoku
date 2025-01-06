#include<iostream>
#include<string>
#include "wspol.hpp"

using namespace std;

int check_intvalue(int a, int b, int x, int y)
{
	string s;
	bool dobrze;
	int v;
	do
	{
		gotoxy(x, y);
		getline(cin, s);
		v = s[0] - '0';
		dobrze = s.size() == 1 && v >= a && v <= b;
		if (!dobrze)
		{
			gotoxy(x, y);
			cout << "\x1B[94m" << "blad ";
			gotoxy(30, 39);
			system("pause");
			gotoxy(30, 39);
			cout << "\x1B[94m" << "                                 ";
			gotoxy(x, y);
			cout << "\x1B[94m" << "    ";
		}

	} while (!dobrze);
	
	return v;
}

char check_charvalue(int x, int y)
{
	char c;
	string s;
	bool dobrze;
	
	do
	{
		gotoxy(x, y);
		getline(cin, s);
		dobrze = (s.size() == 1 && s == "M");
		if (!dobrze)
		{
			gotoxy(x, y);
			cout << "\x1B[94m" << "blad ";
			gotoxy(30, 41);
			system("pause");
			gotoxy(30, 41);
			cout << "\x1B[94m" << "                                 ";
			gotoxy(x, y);
			cout << "\x1B[94m" << "    ";
		}

	} while (!dobrze);
	c = s[0];
	return c;
}

void check_charintvalue(char &l, int&c, int x, int y)
{
	string s;
	bool dobrze;
	do
	{
		gotoxy(x, y);
		getline(cin, s);

		dobrze = (s == "K") || (s.size() == 2 && s[0] >= 'a' && s[0] <= 'i' && s[1] >= '1' && s[1] <= '9');
		if (!dobrze)
		{
			gotoxy(x, y);
			cout << "\x1B[94m" << "blad ";
			gotoxy(30, 39);
			system("pause");
			gotoxy(30, 39);
			cout << "\x1B[94m" << "                                 ";
			gotoxy(x, y);
			cout << "\x1B[94m" << "    ";
		}

	} while (!dobrze);
	c = s[1] - '0';
	l = s[0];
}