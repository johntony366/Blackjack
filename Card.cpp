#include "Card.h"
#include <cassert>
#include <iostream>

void Card::setCard(const Card::Rank rank, const Card::Suit suit)
{
	m_rank = rank;
	m_suit = suit;
}


int Card::getValue() const
{
	switch (m_rank)
	{
	case Rank::two:
		return 2;
	case Rank::three:
		return 3;
	case Rank::four:
		return 4;
	case Rank::five:
		return 5;
	case Rank::six:
		return 6;
	case Rank::seven:
		return 7;
	case Rank::eight:
		return 8;
	case Rank::nine:
		return 9;
	case Rank::ten:
	case Rank::jack:
	case Rank::queen:
	case Rank::king:
		return 10;
	case Rank::ace:
		return 11;
	default:
		assert(false && "Unknown card rank");
		return -1;
	}
}

void Card::printCard() const
{
	switch (m_rank)
	{
	case Rank::two:
		std::cout << "2";
		break;
	case Rank::three:
		std::cout << "3";
		break;
	case Rank::four:
		std::cout << "4";
		break;
	case Rank::five:
		std::cout << "5";
		break;
	case Rank::six:
		std::cout << "6";
		break;
	case Rank::seven:
		std::cout << "7";
		break;
	case Rank::eight:
		std::cout << "8";
		break;
	case Rank::nine:
		std::cout << "9";
		break;
	case Rank::ten:
		std::cout << "T";
		break;
	case Rank::jack:
		std::cout << "J";
		break;
	case Rank::queen:
		std::cout << "Q";
		break;
	case Rank::king:
		std::cout << "K";
		break;
	case Rank::ace:
		std::cout << "A";
		break;
	default:
		assert(false && "Unknown card rank");
		std::cout << "?";
	}

	switch (m_suit)
	{
	case Suit::spades:
		std::cout << "S";
		break;
	case Suit::clubs:
		std::cout << "C";
		break;
	case Suit::hearts:
		std::cout << "H";
		break;
	case Suit::diamonds:
		std::cout << "D";
		break;
	default:
		assert(false && "Unknown card suit");
		std::cout << "?";
	}
}