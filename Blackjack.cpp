#include "Blackjack.h"
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <cassert>

bool Blackjack::startGame()
{
	Deck deck;
	Dealer dealer{ deck };
	std::cout << '\n';
	Player player{ deck };

	bool notBusted = playerTurn(deck, player);
	if (!notBusted)
	{
		std::cout << "\n# You went bust (" << player.getScore() << ") and lost!\n";
		return (playAgainMessage(player, dealer, deck));
		

	}
	notBusted = dealerTurn(deck, dealer);
	if (!notBusted)
	{
		std::cout << "\n# The dealer went bust (" << dealer.getScore() << "), you win!\n";
		return (playAgainMessage(player, dealer, deck));
	}

	switch (endGameStatus(player, dealer))
	{
	case Blackjack::GameStatus::player_win:
		std::cout << "\nYou won!\n";
		return (playAgainMessage(player, dealer, deck));
	case Blackjack::GameStatus::player_loss:
		std::cout << "\nYou lost!\n";
		return playAgainMessage(player, dealer, deck);
	case Blackjack::GameStatus::draw:
		std::cout << "\nDraw!\n";
		return playAgainMessage(player, dealer, deck);
	default:
		assert(false && "Invalid game ending");
		return false;
	}
}


bool Blackjack::playAgainMessage(Player& player, Dealer& dealer, Deck& deck)
{
	std::cout << "\nMATCH SUMMARY\n";
	std::cout << "------------- \n";
	player.printCardsAndScore();
	dealer.printCardsAndScore();
	std::cout << '\n';
	std::cout << "The deck used: ";
	deck.displayDeck();
	std::cout << "\n\n";
	while (true)
	{
		std::cout << "Play again? (y/n): ";

		char choice;
		std::cin >> choice;

		switch (choice)
		{
		case 'y':
			return true;
		case 'n':
			return false;
		default:
			std::cout << "Invalid option! Try again.\n";
			continue;
		}
	}
}

bool Blackjack::playerTurn(Deck& deck, Player& player)
{
	std::cout << '\n';
	while (player.wantsHit())
	{
		const Card& drawnCard{ deck.drawCard() };
		player.acceptCard(drawnCard);
		std::cout << "\n-> You drew "; drawnCard.printCard(); std::cout << " \n";
		if (player.getScore() > 21)
		{
			return false;
		}
		player.printCardsAndScore();
	}
	return true;
}

bool Blackjack::dealerTurn(Deck& deck, Dealer& dealer)
{
	std::cout << '\n';
	while (dealer.getScore() < 17)
	{
		const Card& drawnCard{ deck.drawCard() };
		dealer.acceptCard(drawnCard);
		std::cout << "-> The dealer drew "; drawnCard.printCard(); std::cout << " \n";
		if (dealer.getScore() > 21)
		{
			return false;
		}
	}
	return true;
}

Blackjack::GameStatus Blackjack::endGameStatus(Player& player, Dealer& dealer)
{
	if (player.getScore() > dealer.getScore())
	{
		return GameStatus::player_win;
	}
	else if (player.getScore() < dealer.getScore())
	{
		return GameStatus::player_loss;
	}
	else
	{
		return GameStatus::draw;
	}
}
