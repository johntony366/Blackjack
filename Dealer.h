#pragma once
#include <vector>
#include "Card.h"
#include "Deck.h"

class Dealer
{
private:
	std::vector<Card> m_cards;
	int m_score{ 0 };
	int m_numberOfAces{ 0 };

public:
	Dealer(Deck& deck);
	void acceptCard(Card card);
	void printCards();
	void printScore();
	int getScore();
	void printCardsAndScore();
};