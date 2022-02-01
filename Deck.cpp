#include "Deck.h"
#include <cassert>
#include <random>
#include <ctime>
#include <iostream>

namespace MyRandom
{
	std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}

Deck::Deck()
{
	int index = 0;
	for (int suit = 0; suit < static_cast<int>(Card::Suit::max_suits); ++suit)
	{
		for (int rank = 0; rank < static_cast<int>(Card::Rank::max_rank); ++rank)
		{
			assert(index <= 52);
			m_deck[index++].setCard(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit));
		}
	}
	shuffle();
	m_nextCard = 0;
}

void Deck::shuffle()
{
	std::shuffle(m_deck.begin(), m_deck.end(), MyRandom::mt);
}

void Deck::displayDeck()
{
	for (Card card : m_deck)
	{
		card.printCard(); std::cout << ' ';
	}
	std::cout << '\n';
}

Card Deck::drawCard()
{
	assert(m_nextCard <= 52);
	return m_deck[m_nextCard++];
}