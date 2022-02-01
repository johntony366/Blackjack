#pragma once
class Card
{
public:
	enum class Rank : int
	{
		two,
		three,
		four,
		five,
		six,
		seven,
		eight,
		nine,
		ten,
		jack,
		queen,
		king,
		ace,
		max_rank
	};

	enum class Suit : int
	{
		spades,
		clubs,
		hearts,
		diamonds,
		max_suits
	};

private:
	Rank m_rank;
	Suit m_suit;

public:
	void setCard(const Rank rank, const Suit suit); //construct the card
	int getValue() const; //returns the value of the card
	void printCard() const; //display the card Eg: "5H"
};

