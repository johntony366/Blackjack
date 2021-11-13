// a) A deck of cards has 52 unique cards (13 card ranks of 4 suits). Create enumerations for the card ranks (2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace) and suits (clubs, diamonds, hearts, spades). Those enumerators will not be used to index arrays.

#include "main.h"
#include "functions.h"
#include <iostream>
#include <cassert>

int main()
{
    deck_type deck{ createDeck() };
    shuffleDeck(deck);
    switch (playBlackjack(deck))
    {
    case BlackjackResult::player_wins:  std::cout << "You win!\n"; break;
    case BlackjackResult::dealer_wins:  std::cout << "You lost! Better luck next time.\n"; break;
    case BlackjackResult::tie:  std::cout << "Tie!\n"; break;
    default:    assert(false && "Unidentified Blackjack result"); break;
    }
    return 0;
}