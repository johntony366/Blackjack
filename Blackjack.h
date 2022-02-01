#pragma once
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

class Blackjack
{
public:
	enum class GameStatus
	{
		player_win,
		player_loss,
		draw
	};
public:
	bool playAgainMessage(Player& player, Dealer& dealer, Deck& deck);
	bool startGame();
	bool playerTurn(Deck& deck, Player& player);
	bool dealerTurn(Deck& deck, Dealer& dealer);
	GameStatus endGameStatus(Player& player, Dealer& dealer);
};

