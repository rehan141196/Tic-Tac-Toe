#include <iostream>
#include "SquareSpot.h"
using namespace std;

SquareSpot sq1(1);
SquareSpot sq2(2);
SquareSpot sq3(3);
SquareSpot sq4(4);
SquareSpot sq5(5);
SquareSpot sq6(6);
SquareSpot sq7(7);
SquareSpot sq8(8);
SquareSpot sq9(9);

void drawGrid();
bool PlayTurn(int playerNumber, char playerChar);
void clearScreen();
bool checkTrio();
void reset();
bool checkDraw();

int main()
{
	drawGrid();
	for (int turn = 1; ; turn++)
	{
		bool turnPlayed;
		if (turn % 2 == 1)
			turnPlayed = PlayTurn(1, 'X');
		else
			turnPlayed = PlayTurn(2, 'O');
		if (turnPlayed == false)
		{
			clearScreen();
			drawGrid();
			cout << endl;
			cout << "Grid position is occupied! Try again!" << endl;
			turn--;
			continue;
		}
		clearScreen();
		drawGrid();
		
		if (checkTrio() || checkDraw())
		{
			if (checkTrio())
			{
				if (turn % 2 == 1)
					cout << "Player 1 wins!" << endl;
				else
					cout << "Player 2 wins!" << endl;
			}
			else if (checkDraw())
				cout << "Match Drawn!" << endl;
			char newGame;
			cout << "New Game? (Y/N): ";
			cin >> newGame;
			newGame = toupper(newGame);
			if (newGame == 'Y')
			{
				reset();
				clearScreen();
				drawGrid();
			}
			else
				return 1;
		}
	}
}

bool PlayTurn(int playerNumber, char playerChar)
{
	int posEntered;

	for (;;)
	{
		cout << endl;
		cout << "Player " << playerNumber <<  " enter a grid position from 1 to 9 : ";
		cin >> posEntered;
		if (posEntered < 1 || posEntered > 9)
			cout << "Wrong position entered! Try again" << endl;
		else
			break;
	}

	switch (posEntered)
	{
	case 1:
		if (sq1.isSpace() == true)
			sq1.setSign(playerChar);
		else
			return false;
		break;
	case 2:
		if (sq2.isSpace() == true)
			sq2.setSign(playerChar);
		else
			return false;
		break;
	case 3:
		if (sq3.isSpace() == true)
			sq3.setSign(playerChar);
		else
			return false;
		break;
	case 4:
		if (sq4.isSpace() == true)
			sq4.setSign(playerChar);
		else
			return false;
		break;
	case 5:
		if (sq5.isSpace() == true)
			sq5.setSign(playerChar);
		else
			return false;
		break;
	case 6:
		if (sq6.isSpace() == true)
			sq6.setSign(playerChar);
		else
			return false;
		break;
	case 7:
		if (sq7.isSpace() == true)
			sq7.setSign(playerChar);
		else
			return false;
		break;
	case 8:
		if (sq8.isSpace() == true)
			sq8.setSign(playerChar);
		else
			return false;
		break;
	case 9:
		if (sq9.isSpace() == true)
			sq9.setSign(playerChar);
		else
			return false;
		break;
	}
	return true;
}

void drawGrid()
{
	int breadth = 1;
	for (int length = 0; length < 15; length++)
	{
		if (length == 2 || length == 7 || length == 12)
		{
			char SqSign1 = 'f';
			char SqSign2 = 'f';
			char SqSign3 = 'f';
			if (length == 2)
			{
				SqSign1 = sq1.getSqSign();
				SqSign2 = sq2.getSqSign();
				SqSign3 = sq3.getSqSign();
			}
			else if (length == 7)
			{
				SqSign1 = sq4.getSqSign();
				SqSign2 = sq5.getSqSign();
				SqSign3 = sq6.getSqSign();
			}
			else
			{
				SqSign1 = sq7.getSqSign();
				SqSign2 = sq8.getSqSign();
				SqSign3 = sq9.getSqSign();
			}
			cout << "    " << SqSign1 << "    |    " << SqSign2 << "    |    " << SqSign3 << endl;
			breadth++;
			continue;
		}
		cout << "         |         |" << endl;
		if (breadth == 5 || breadth == 10)
			cout << "-------------------------------" << endl;
		breadth++;
	}
}

bool checkTrio()
{
	if (sq1.getSqSign()!=' ' && sq1.getSqSign() == sq2.getSqSign() && sq2.getSqSign() == sq3.getSqSign())
		return true;
	else if (sq1.getSqSign() != ' ' && sq1.getSqSign() == sq4.getSqSign() && sq4.getSqSign() == sq7.getSqSign())
		return true;
	else if (sq1.getSqSign() != ' ' && sq1.getSqSign() == sq5.getSqSign() && sq5.getSqSign() == sq9.getSqSign())
		return true;
	else if (sq4.getSqSign() != ' ' && sq4.getSqSign() == sq5.getSqSign() && sq5.getSqSign() == sq6.getSqSign())
		return true;
	else if (sq7.getSqSign() != ' ' && sq7.getSqSign() == sq8.getSqSign() && sq8.getSqSign() == sq9.getSqSign())
		return true;
	else if (sq2.getSqSign() != ' ' && sq2.getSqSign() == sq5.getSqSign() && sq5.getSqSign() == sq8.getSqSign())
		return true;
	else if (sq3.getSqSign() != ' ' && sq3.getSqSign() == sq6.getSqSign() && sq6.getSqSign() == sq9.getSqSign())
		return true;
	else if (sq3.getSqSign() != ' ' && sq3.getSqSign() == sq5.getSqSign() && sq5.getSqSign() == sq7.getSqSign())
		return true;
	else
		return false;
}

void reset()
{
	sq1.setSign(' ');
	sq2.setSign(' ');
	sq3.setSign(' ');
	sq4.setSign(' ');
	sq5.setSign(' ');
	sq6.setSign(' ');
	sq7.setSign(' ');
	sq8.setSign(' ');
	sq9.setSign(' ');
}

bool checkDraw()
{
	if (sq1.getSqSign() == ' ' || sq2.getSqSign() == ' ' || sq3.getSqSign() == ' ' || sq4.getSqSign() == ' ' || sq5.getSqSign() == ' ' || sq6.getSqSign() == ' ' || sq7.getSqSign() == ' ' || sq8.getSqSign() == ' ' || sq9.getSqSign() == ' ')
		return false;
	else
		return true;
}

//  clearScreen implementations

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	COORD upperLeft = { 0, 0 };
	DWORD dwCharsWritten;
	FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
		&dwCharsWritten);
	SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
	static const char* term = getenv("TERM");
	if (term == nullptr || strcmp(term, "dumb") == 0)
		cout << endl;
	else
	{
		static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
		cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
	}
}

#endif