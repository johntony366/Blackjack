#pragma once
#include "main.h"

bool startMenu(deck_type& deck, bool& no_exit);
void printCard(const Card& card);
template <typename T> void printCards(const T& cards);
deck_type createDeck();
void printDeck(const deck_type& deck);
void shuffleDeck(deck_type& deck);
int getCardValue(const Card& card);
BlackjackResult playBlackjack(const deck_type& deck);