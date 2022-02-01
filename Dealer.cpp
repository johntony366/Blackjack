#include "Dealer.h"
#include <iostream>

Dealer::Dealer(Deck& deck)
{
	acceptCard(deck.drawCard());
	printCards();
	std::cout << '\n';
	printScore();
}

void Dealer::printCards()
{
	std::cout << "The dealers cards are: ";
	for (Card card : m_cards)
	{
		card.printCard();
		std::cout << " ";
	}
}

void Dealer::printScore()
{
	std::cout << "The dealers score is: " << getScore() << '\n';
}

int Dealer::getScore()
{
	while(m_score > 21 && m_numberOfAces > 0)
	{
		m_score -= 10;
		--m_numberOfAces;
	}
	return m_score;
}

void Dealer::acceptCard(Card card)
{
	m_cards.push_back(card);
	m_score += card.getValue();
	if (card.getValue() == 11)
	{
		++m_numberOfAces;
	}
}

void Dealer::printCardsAndScore()
{
	std::cout << '\n';
	printCards();
	std::cout << '\n';
	printScore();
	std::cout << '\n';
}