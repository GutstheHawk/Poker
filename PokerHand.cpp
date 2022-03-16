#include <iomanip>
#include <iostream>
#include <string>
#include "PokerHand.h"
#include "DeckOfCards.h"
using namespace std;

PokerHand::PokerHand()
{
	DeckOfCards defaultDeck;
	defaultDeck.shuffle();
	for (int i = 0; i < 5; i++)
	{
		hand[i] = defaultDeck.dealCard();
	}

	//Sort by face value rank min to max

	int min;

	for (int i = 0; i < 5; i++)
	{
		min = i;

		for (int j = i + 1; j < 5; j++)
		{
			if (hand[j].getFace() < hand[min].getFace())
			{
				min = j;
			}
		}

		Card temp = hand[i];
		hand[i] = hand[min];
		hand[min] = temp;
	}
}

PokerHand::PokerHand(int face_1, int suit_1, int face_2, int suit_2, int face_3, int suit_3, int face_4, int suit_4, int face_5, int suit_5)
{
	Card card1(face_1, suit_1);
	hand[0] = card1;
	Card card2(face_2, suit_2);
	hand[1] = card2;
	Card card3(face_3, suit_3);
	hand[2] = card3;
	Card card4(face_4, suit_4);
	hand[3] = card4;
	Card card5(face_5, suit_5);
	hand[4] = card5;

	//Sort by face value rank min to max

	int min;

	for (int i = 0; i < 5; i++)
	{
		min = i;

		for (int j = i + 1; j < 5; j++)
		{
			if (hand[j].getFace() < hand[min].getFace())
			{
				min = j;
			}
		}

		Card temp = hand[i];
		hand[i] = hand[min];
		hand[min] = temp;
	}
}

void PokerHand::setHand()
{
	int tempFace;
	int tempSuit;

	for (int i = 0; i < 5; i++)
	{
		cout << "Enter the value for the face of a card: (0 = Ace, 10 = Jack, 11 = Queen, 12 = king)";
		cin >> tempFace;
		cout << "Enter the value for the suit of a card: (0 = spades, 1 = clubs, 2 = diamonds, 3 = hearts)";
		cin >> tempSuit;
		Card tempCard(tempFace, tempSuit);
		hand[i] = tempCard;
	}

	//Sort by face value rank min to max

	int min;

	for (int i = 0; i < 5; i++)
	{
		min = i;

		for (int j = i + 1; j < 5; j++)
		{
			if (hand[j].getFace() < hand[min].getFace())
			{
				min = j;
			}
		}

		Card temp = hand[i];
		hand[i] = hand[min];
		hand[min] = temp;
	}
}

void PokerHand::seeHand()
{
	for (int i = 0; i < 5; i++)
	{
		cout << hand[i].toString() << endl;
	}
}

bool PokerHand::pairCheck()
{
	if (threeKindCheck() || fourKindCheck() || twoPairCheck())
	{
		return false;
	}
	else
	{
		bool pos1, pos2, pos3, pos4;

		pos1 = hand[0].getFace() == hand[1].getFace();

		pos2 = hand[1].getFace() == hand[2].getFace();

		pos3 = hand[2].getFace() == hand[3].getFace();

		pos4 = hand[3].getFace() == hand[4].getFace();

		return(pos1 || pos2 || pos3|| pos4);
	}
}

bool PokerHand::twoPairCheck()
{
	if (threeKindCheck() || fourKindCheck())
	{
		return false;
	}
	else
	{
		bool pos1, pos2, pos3;

		pos1 = hand[0].getFace() == hand[1].getFace() &&
			hand[2].getFace() == hand[3].getFace();

		pos2 = hand[0].getFace() == hand[1].getFace() &&
			hand[3].getFace() == hand[4].getFace();

		pos3 = hand[1].getFace() == hand[2].getFace() &&
			hand[3].getFace() == hand[4].getFace();

		return(pos1 || pos2 || pos3);
	}
}

bool PokerHand::threeKindCheck()
{
	if (fourKindCheck())
	{
		return false;
	}
	else
	{
		bool pos1, pos2, pos3;

		pos1 = hand[0].getFace() == hand[1].getFace() &&
			hand[1].getFace() == hand[2].getFace() &&
			hand[3].getFace() != hand[0].getFace() &&
			hand[4].getFace() != hand[0].getFace() &&
			hand[3].getFace() != hand[4].getFace();

		pos2 = hand[1].getFace() == hand[2].getFace() &&
			hand[2].getFace() == hand[3].getFace() &&
			hand[0].getFace() != hand[1].getFace() &&
			hand[4].getFace() != hand[1].getFace() &&
			hand[0].getFace() != hand[4].getFace();

		pos3 = hand[2].getFace() == hand[3].getFace() &&
			hand[3].getFace() == hand[4].getFace() &&
			hand[0].getFace() != hand[2].getFace() &&
			hand[1].getFace() != hand[2].getFace() &&
			hand[0].getFace() != hand[1].getFace();

		return(pos1 || pos2 || pos3);
	}
}

bool PokerHand::fourKindCheck()
{
	bool pos1, pos2;

	pos1 = hand[0].getFace() == hand[1].getFace() &&
		hand[1].getFace() == hand[2].getFace() &&
		hand[2].getFace() == hand[3].getFace();

	pos2 = hand[1].getFace() == hand[2].getFace() &&
		hand[2].getFace() == hand[3].getFace() &&
		hand[3].getFace() == hand[4].getFace();

	return(pos1 || pos2);
}

bool PokerHand::flushCheck()
{
	int matchCount = 0;

	for (int i = 1; i < 5; i++)
	{
		if (hand[0].getSuit() == hand[i].getSuit())
		{
			matchCount++;
		}
	}

	if (matchCount == 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool PokerHand::straightCheck()
{
	int matchCount = 0;

	for (int i = 1; i < 5; i++)
	{
		if (hand[0 + i].getFace() == (hand[0].getFace() + i))
		{
			matchCount++;
		}
	}

	if (matchCount == 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}
