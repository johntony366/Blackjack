#pragma once
#include <array>
#include "Card.h"

class Deck
{
private:
	std::array<Card, 52> m_deck;
	int m_nextCard;

public:
	Deck();
	void shuffle();
	void displayDeck();
	Card drawCard();
};

