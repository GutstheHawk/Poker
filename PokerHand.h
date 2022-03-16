#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include "Card.h"
using namespace std;

class PokerHand
{
private:
	Card hand[5];

public:
	PokerHand();

	PokerHand(int, int, int, int, int, int, int, int, int, int);

	void setHand();

	void seeHand();

	bool pairCheck();

	bool twoPairCheck();

	bool threeKindCheck();

	bool fourKindCheck();

	bool flushCheck();

	bool straightCheck();
};