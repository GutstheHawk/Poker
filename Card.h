#pragma once
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Card
{
private:
	int face;

	int suit;

	static const string suits[4];

	static const string faces[13];

public:

	Card();

	Card(int, int);

	int getSuit();

	void setSuit(int);

	int getFace();

	void setFace(int);

	string toString();

};