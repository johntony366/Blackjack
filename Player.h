#pragma once
#include <vector>
#include "Card.h"
#include "Deck.h"

class Player
{
private:
	std::vector<Card> m_cards;
	int m_score{ 0 };
	int m_numberOfAces{ 0 };

public:
	Player(Deck& deck);
	void printCards();
	void acceptCard(Card card);
	int getScore();
	void printScore();
	bool wantsHit();
	void printCardsAndScore();
};

