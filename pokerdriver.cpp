// Homework 1 Cards BM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <string>
#include "Card.h"
#include "PokerHand.h"
#include "DeckOfCards.h"

int main()
{
	PokerHand testHand;
	testHand.seeHand();
	cout << testHand.pairCheck() << endl;
	cout << testHand.twoPairCheck() << endl;
	cout << testHand.threeKindCheck() << endl;
	cout << testHand.fourKindCheck() << endl;
	cout << testHand.flushCheck() << endl;
	cout << testHand.straightCheck() << endl << endl;

	PokerHand pairHand(9, 1, 5, 2, 7, 0, 9, 2, 3, 1);
	pairHand.seeHand();
	cout << pairHand.pairCheck() << endl << endl;

	PokerHand twoPairHand(7, 1, 11, 2, 7, 2, 5, 1, 5, 0);
	twoPairHand.seeHand();
	cout << twoPairHand.twoPairCheck() << endl << endl;

	PokerHand threeKindHand(9, 1, 5, 2, 9, 3, 9, 0, 12, 1);
	threeKindHand.seeHand();
	cout << threeKindHand.threeKindCheck() << endl << endl;

	PokerHand fourKindHand(3, 1, 10, 1, 3, 0, 3, 2, 3, 3);
	fourKindHand.seeHand();
	cout << fourKindHand.fourKindCheck() << endl << endl;

	PokerHand flushHand(9, 1, 5, 1, 7, 1, 12, 1, 11, 1);
	flushHand.seeHand();
	cout << flushHand.flushCheck() << endl << endl;

	PokerHand straightHand(3, 2, 4, 1, 5, 3, 6, 1, 7, 2);
	straightHand.seeHand();
	cout << straightHand.straightCheck() << endl << endl;





}
