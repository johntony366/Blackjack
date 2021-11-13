#pragma once
#include "main.h"

void printCard(const Card& card);
deck_type createDeck();
void printDeck(const deck_type& deck);
void shuffleDeck(deck_type& deck);
int getCardValue(const Card& card);
BlackjackResult playBlackjack(const deck_type& deck);