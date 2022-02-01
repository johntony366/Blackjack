#include "Player.h"
#include <iostream>

Player::Player(Deck& deck)
{
	acceptCard(deck.drawCard());
	acceptCard(deck.drawCard());
	printCards();
	std::cout << '\n';
	printScore();
}

void Player::printCards()
{
	std::cout << "The players cards are: ";
	for (Card card : m_cards)
	{
		card.printCard();
		std::cout << " ";
	}
}

void Player::printScore()
{
	
	std::cout << "The players score is: " << getScore() << '\n';
}

bool Player::wantsHit()
{
	std::cout << "Press \"h\" to hit and \"s\" to stand: ";
	
	char action{ };
	while (true)
	{
		std::cin >> action;

		switch (action)
		{
		case 'h':
			return true;
		case 's':
			return false;
		default:
			std::cout << "Invalid option! Try again.\n";
		}
	}
}

int Player::getScore()
{
	while (m_score > 21 && m_numberOfAces > 0)
	{
		m_score -= 10;
		--m_numberOfAces;
	}
	return m_score;
}

void Player::acceptCard(Card card)
{
	m_cards.push_back(card);
	m_score += card.getValue();
	if (card.getValue() == 11)
	{
		++m_numberOfAces;
	}
}

void Player::printCardsAndScore()
{
	std::cout << '\n';
	printCards();
	std::cout << '\n';
	printScore();
	std::cout << '\n';
}