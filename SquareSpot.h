#ifndef SQUARESPOT_INCLUDED
#define SQUARESPOT_INCLUDED

#include <iostream>
using namespace std;

class SquareSpot
{
public:
	SquareSpot(int number);
	int getSqNumber();
	char getSqSign();
	void setSign(char sign);
	bool isSpace();
private:
	int squarenumber;
	char signInSquare;
};

SquareSpot::SquareSpot(int number)
{
	squarenumber = number;
	signInSquare = ' ';
}

int SquareSpot::getSqNumber()
{
	return squarenumber;
}

char SquareSpot::getSqSign()
{
	return signInSquare;
}

void SquareSpot::setSign(char sign)
{
	signInSquare = sign;
}

bool SquareSpot::isSpace()
{
	if (signInSquare == ' ')
		return true;
	else
		return false;
}

#endif // SQUARESPOT_INCLUDED