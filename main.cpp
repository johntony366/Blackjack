#include "main.h"
#include "functions.h"
#include <iostream>
#include <cassert>
#include <limits>

int main()
{
    deck_type deck{ createDeck() };
    while (true)
    {
        if (!startMenu(deck))
        {
            continue;
        }

        switch (playBlackjack(deck))
        {
        case BlackjackResult::player_wins:  std::cout << "You win!\n\n"; break;
        case BlackjackResult::dealer_wins:  std::cout << "You lost! Better luck next time.\n\n"; break;
        case BlackjackResult::tie:  std::cout << "Tie!\n"; break;
        default:    assert(false && "Unidentified Blackjack result"); break;
        }
    }
    return 0;
}
