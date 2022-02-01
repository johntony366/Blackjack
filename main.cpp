#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "Dealer.h"
#include "Blackjack.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

int main()
{
	Blackjack blackjack;
	bool keepPlaying = true;
	while (keepPlaying)
	{
		keepPlaying = blackjack.startGame();
		
	}
	return 0;
}