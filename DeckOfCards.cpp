#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>
#include "DeckOfCards.h"
using namespace std;

DeckOfCards::DeckOfCards()
{
	currentCard = 0;
	int cardIndex = 0;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 13; i++)
		{
			Card tempCard(i, j);
			deck[cardIndex] = tempCard;
			cardIndex += 1;
		}
	}
}

void DeckOfCards::shuffle()
{
	srand(time(NULL));
	for (int i = 0; i < 52; i++)
	{
		int randint = (rand() % 52);
		//cout << randint << endl;
		Card tempCard;

		tempCard = deck[i];
		deck[i] = deck[randint];
		deck[randint] = tempCard;
	}
}

Card DeckOfCards::dealCard()
{
	currentCard += 1;
	return deck[currentCard - 1];
}

bool DeckOfCards::moreCards()
{
	if (currentCard > 51)
	{
		return false;
	}
	else
	{
		return true;
	}
}