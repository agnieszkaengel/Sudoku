#include<iostream>
#include<fstream>
#include"files.hpp"
#include"Player.hpp"
#include"frame.hpp"
#include"control.hpp"

using namespace std;

string create_filename(string nick1, string nick2)
{
	if (nick1 < nick2)
		return (nick1 + nick2 + ".txt"); //nazwa postaci: nick1nick2.txt
	else
		return (nick2 + nick1 + ".txt");
}

bool check_ifexists(string filename)
{
	ifstream file;//odczyt
	file.open(filename, ios::in);
	if (file.good())
	{
		file.close();
		return true;
	}
	else
		return false;

}

bool check_ifempty(string filename)
{
	ifstream file;
	file.open(filename, ios::in);
	 
	if (file.peek() == EOF)
		return true;
	else
		return false;
}

bool continue_choice(string filename)
{
	
	if (check_ifexists(filename) && !check_ifempty(filename))
	{
		print_frame(47, 2, 23, 30);
		gotoxy(27, 31);
		cout << "\x1B[94m" << "Czy chcesz kontynuowac poprzednia gre?";
		gotoxy(27, 32);
		cout << "\x1B[94m" << "1) tak 2) nie: ";
		int n = check_intvalue(1, 2, 42, 32);
		if (n == 1)
			return true;
		else if(n==2)
		{
			const char* name = filename.c_str();
			remove(name);
		}
	}
	
	return false;
}

void write_infile(string filename, Board board, Player* player1, Player* player2)
{
	ofstream file;
	file.open(filename, ios::out | ios::trunc);

	{
		for (int i = 0; i < P; i++)
		{
			for (int j = 0; j < P; j++)
			{
				file << board.get_value(i, j) << " ";
			}
			file << endl;
		}

		if (player2 != NULL)
		{
			if (player1->get_nick() < player2->get_nick())
			{
				file << player1->get_score() << endl;
				file << player2->get_score() << endl;
			}
			else
			{
				file << player2->get_score() << endl;
				file << player1->get_score() << endl;
			}
		}
		else
			file << player1->get_score() << endl;
		

	}
}

