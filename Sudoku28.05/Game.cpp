#include"iostream"

#include"Game.hpp"
#include"control.hpp"
#include"files.hpp"
#include"frame.hpp"
#include"wspol.hpp"
#include"Inst.hpp"
#include"Menu.hpp"
#include"Player.hpp"
#include"Board.hpp"

int Game::get_selection(void)
{
	gotoxy(48, 24);
	int w = check_intvalue(1, 4, 48, 24);
	return w;
}

void Game::prepare_screen(int w)
{
	char m;
	system("CLS");
	switch (w)
	{
	case 1:
		inst.print_inst();
		gotoxy(59, 38);
		//char m;
		m = check_charvalue(59, 38);
		system("CLS");
		menu.print_menu();
		break;

	case 2:
		board.print_board_1player();

		gotoxy(12, 34);
		cout << (player1->get_nick());

		gotoxy(14, 35);
		cout << player1->get_score();
		break;

	case 3: case 4:
		board.print_board_2players();

		gotoxy(12, 34);
		cout << (player1->get_nick());
		gotoxy(14, 35);
		cout << player1->get_score();

		gotoxy(77, 34);
		cout << player2->get_nick();
		gotoxy(79, 35);
		cout << player2->get_score();
		break;
	}
}

void Game::get_nicks(int w, string& filename)
{
	string nick;
	system("CLS");
	switch (w)
	{
	case 2:

		menu.print_graczemenu(1);
		gotoxy(36, 20);
		getline(cin, nick);
		player1 = new HumanPlayer(nick, &board);
		filename = create_filename(player1->get_nick(), "");
		break;

	case 3:

		menu.print_graczemenu(2);

		player1 = new AutoPlayer(&board);

		gotoxy(36, 20);
		cout << player1->get_nick();

		gotoxy(36, 24);
		getline(cin, nick);
		player2 = new HumanPlayer(nick, &board);

		filename = create_filename(player1->get_nick(), player2->get_nick());
		break;

	case 4:
		menu.print_graczemenu(2);

		gotoxy(36, 20);
		getline(cin, nick);
		player1 = new HumanPlayer(nick, &board);

		gotoxy(36, 24);
		getline(cin, nick);
		player2 = new HumanPlayer(nick, &board);

		filename = create_filename(player1->get_nick(), player2->get_nick());
		break;

	default:
		break;
	}
}

void Game::play(void)
{
	menu.print_menu();
	int s = 1;
	int s1, s2;
	string filename;
	while (s == 1)
	{
		s = get_selection();
		get_nicks(s, filename);
		if (s != 1)
		{
			if (continue_choice(filename))
			{
				board.read_board(filename, s1, s2);
				if (player2 != NULL)
				{
					if (player1->get_nick() < player2->get_nick())
					{
						player1->modify_score(s1);
						player2->modify_score(s2);
					}
					else
					{
						player1->modify_score(s2);
						player2->modify_score(s1);
					}
				}
				else
					player1->modify_score(s1);
			}
			else
				board.read_board(board.draw_board(), s1, s2);
		}
		prepare_screen(s);
	}
	Player* czyja_kolej = player1;


	while (!board.isSolved())
	{
		//prepare_screen(s);
		gotoxy(31, 30);
		cout << "GRACZ: " << czyja_kolej->get_nick();
		int x, y, v;
		char c;
		do
		{
			czyja_kolej->getMove(c, y, v);

			if (c == 'K')
			{
				end_of_game();

				exit(0);
			}

			x = board.convert(c);

			if (!board.isFree(x, y))
			{
				gotoxy(45, 33);
				cout << "ZAJETE POLE";
				gotoxy(30, 40);
				system("pause");
				gotoxy(30, 40);
				cout << "                                 ";
				gotoxy(56, 32);
				cout << "  ";
				gotoxy(45, 33);
				cout << "           ";
			}

		} while (!board.isFree(x, y));

		if (board.isCorrect(x, y, v))
		{
			czyja_kolej->modify_score(2);
			board.put(x, y, v);
		}
		else
			czyja_kolej->modify_score(-1);

		if (czyja_kolej == player1 && player2 != NULL)
			czyja_kolej = player2;

		else if (czyja_kolej == player2)
			czyja_kolej = player1;

		write_infile(filename, board, player1, player2);

		board.start.x = (Columns - BWidth) / 2;
		board.start.y = 10;
		if(!board.isSolved())
			prepare_screen(s);
	}
	const char* name = filename.c_str();
	remove(name);
	end_of_game();
}

void Game::end_of_game(void)
{
	system("CLS");
	print_frame(Columns, Rows, 0, 0);

	gotoxy(27, 4);
	cout << " _               _";
	gotoxy(27, 5);
	cout << "| | _____  _ __ (_) ___  ___";
	gotoxy(27, 6);
	cout << "| |/ / _ " << char(92) << "| '_ " << char(92) << "| |/ _ " << char(92) << "/__ |";
	gotoxy(27, 7);
	cout << "|   < (_) | | | | |  __/ (__";
	gotoxy(27, 8);
	cout << "|_|" << char(92) << "_" << char(92) << "___/|_| |_|_|" << char(92) << "___|" << char(92) << "___| __ _   _";
	gotoxy(27, 9);
	cout << "                      / _` | '__| | | |";
	gotoxy(27, 10);
	cout << "                     | (_| | |  | |_| |";
	gotoxy(27, 11);
	cout << "                      " << char(92) << "__, |_|   " << char(92) << "__, |";
	gotoxy(27, 12);
	cout << "                      |___/      |___/";

	print_frame(31, 7, 31, 15);
	gotoxy(0, 50);

	cout << "\x1B[94m";
	if (player2 != NULL)
	{
		if (player1->get_score() > player2->get_score())
		{
			gotoxy(35, 17);
			cout << "WYGRANY";
			gotoxy(35, 19);
			cout << char(254) << " gracz: " << player1->get_nick();
			gotoxy(35, 20);
			cout << char(254) << " punkty: " << player1->get_score();
		}
		else if (player1->get_score() == player2->get_score())
		{
			gotoxy(35, 17);
			cout << "REMIS";
			gotoxy(35, 19);
			cout << char(254) << " gracze: " << player1->get_nick();
			gotoxy(45, 20);
			cout << player2->get_nick();
			gotoxy(35, 21);
			cout << char(254) << " punkty: " << player2->get_score();
		}
		else
		{
			gotoxy(35, 17);
			cout << "WYGRANY";
			gotoxy(35, 19);
			cout << char(254) << " gracz: " << player2->get_nick();
			gotoxy(35, 20);
			cout << char(254) << " punkty: " << player2->get_score();
		}
	}
	else
	{
		gotoxy(35, 17);
		cout << "TWOJ WYNIK";
		gotoxy(35, 19);
		cout << char(254) << " gracz: " << player1->get_nick();
		gotoxy(35, 20);
		cout << char(254) << " punkty: " << player1->get_score();
	}

	gotoxy(0, 43);
	system("pause>nul");
	system("CLS");
}