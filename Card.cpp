#include <iomanip>
#include <iostream>
#include <string>
#include "Card.h"
using namespace std;

const string Card::suits[4] = { "spades", "clubs", "diamonds", "hearts" };

const string Card::faces[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

Card::Card()
{
	suit = 0;
	face = 0;
}

Card::Card(int t_face, int t_suit)
{
	face = t_face;
	suit = t_suit;
}

int Card::getSuit()
{
	return suit;
}

void Card::setSuit(int t_suit)
{
	suit = t_suit;
}

int Card::getFace()
{
	return face;
}

void Card::setFace(int t_face)
{
	face = t_face;
}

string Card::toString()
{
	string temp = faces[face] + " of " + suits[suit];
	return temp;
}