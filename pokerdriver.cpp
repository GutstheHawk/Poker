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
	cout << "Check For A Pair: " << testHand.pairCheck() << endl;
	cout << "Check For Two Pairs: " << testHand.twoPairCheck() << endl;
	cout << "Check For Three of a Kind: " << testHand.threeKindCheck() << endl;
	cout << "Check For Four of a Kind: " << testHand.fourKindCheck() << endl;
	cout << "Check For A Flush: " << testHand.flushCheck() << endl;
	cout << "Check For A Straight: " << testHand.straightCheck() << endl << endl;

	PokerHand pairHand(9, 1, 5, 2, 7, 0, 9, 2, 3, 1);
	pairHand.seeHand();
	cout << "Check For A Pair: " << pairHand.pairCheck() << endl << endl;

	PokerHand twoPairHand(7, 1, 11, 2, 7, 2, 5, 1, 5, 0);
	twoPairHand.seeHand();
	cout << "Check For Two Pairs: " << twoPairHand.twoPairCheck() << endl << endl;

	PokerHand threeKindHand(9, 1, 5, 2, 9, 3, 9, 0, 12, 1);
	threeKindHand.seeHand();
	cout << "Check For A Flush: " << threeKindHand.flushCheck() << endl << endl;

	PokerHand fourKindHand(3, 1, 10, 1, 3, 0, 3, 2, 3, 3);
	fourKindHand.seeHand();
	cout << "Check For Four of a Kind: " << fourKindHand.fourKindCheck() << endl << endl;

	PokerHand flushHand(9, 1, 5, 1, 7, 1, 12, 1, 11, 1);
	flushHand.seeHand();
	cout << "Check For A Flush: " << flushHand.flushCheck() << endl << endl;

	PokerHand straightHand(3, 2, 4, 1, 5, 3, 6, 1, 7, 2);
	straightHand.seeHand();
	cout << "Check For A Straight: " << straightHand.straightCheck() << endl << endl;
}
