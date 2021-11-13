#include "main.h"
#include "functions.h"
#include <iostream>
#include <array>
#include <ctime>
#include <algorithm>
#include <random>
#include <cassert>
#include <limits>

void printCard(const Card& card)
{
    switch (card.cardRank)
    {
        case CardRank::rank_2:      std::cout << "2"; break;
        case CardRank::rank_3:      std::cout << "3"; break;
        case CardRank::rank_4:      std::cout << "4"; break;
        case CardRank::rank_5:      std::cout << "5"; break;
        case CardRank::rank_6:      std::cout << "6"; break;
        case CardRank::rank_7:      std::cout << "7"; break;
        case CardRank::rank_8:      std::cout << "8"; break;
        case CardRank::rank_9:      std::cout << "9"; break;
        case CardRank::rank_10:     std::cout << "T"; break;
        case CardRank::rank_jack:   std::cout << "J"; break;
        case CardRank::rank_queen:  std::cout << "Q"; break;
        case CardRank::rank_king:   std::cout << "K"; break;
        case CardRank::rank_ace:    std::cout << "A"; break;
        default: std::cout << "?"; break;
    }
    switch (card.cardSuit)
    {
        case CardSuit::club:    std::cout << "C"; break;
        case CardSuit::diamond: std::cout << "D"; break;
        case CardSuit::heart:   std::cout << "H"; break;
        case CardSuit::spade:   std::cout << "S"; break;
        default: std::cout << "?"; break;
    }
}

deck_type createDeck()
{
    index_type index{ 0 };

    deck_type deck{ };
    for (int suit{ 0 }; suit < static_cast<int>(CardSuit::max_suits); ++suit)
    {
        for (int rank{ 0 }; rank < static_cast<int>(CardRank::max_ranks); ++rank)
        {
            deck[index].cardRank = static_cast<CardRank>(rank);
            deck[index].cardSuit = static_cast<CardSuit>(suit);
            ++index;
        }
    }
    return deck;
}

template <typename T>
void printCards(const T& cards)
{
    for (Card card : cards)
    {
        printCard(card);
        std::cout << ' ';
    }
    std::cout << '\n';
}

void shuffleDeck(deck_type& deck)
{
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::shuffle(deck.begin(), deck.end(), mt);
}

int getCardValue(const Card& card)
{
    switch (card.cardRank)
    {
        case CardRank::rank_2:
        case CardRank::rank_3:
        case CardRank::rank_4:
        case CardRank::rank_5:
        case CardRank::rank_6:
        case CardRank::rank_7:
        case CardRank::rank_8:
        case CardRank::rank_9:
        case CardRank::rank_10:
            return static_cast<int>(card.cardRank)+2;
        case CardRank::rank_jack:
        case CardRank::rank_queen:
        case CardRank::rank_king:
            return 10;
        case CardRank::rank_ace:
            return 11;
        default:
            assert(false && "Unknown Rank");
            return 0;
    }
}

bool isAce(const Card& card)
{
    return (card.cardRank == CardRank::rank_ace);
}

void displayCardsAndScores(Dealer& dealer, Player& player)
{
    std::cout << "The dealer's cards are: ";
    printCards(dealer.cards);
    std::cout << "The dealer's score is: " << dealer.score << "\n\n";
    std::cout << "Your cards are: ";
    printCards(player.cards);
    std::cout << "Your score is: " << player.score << '\n';
}

bool playerWantsHit()
{
    while (true)
    {
        std::cout << "h -> hit\ns -> stand\nEnter your choice: ";
        char choice{ };
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
            case 'h': std::cout <<  "You chose to hit!\n";   return true;
            case 's': std::cout <<  "You chose to stand!\n"; return false;
            default:    std::cout <<"Please try again!\n";  continue;
        }
    }
}

template <typename T>
bool checkPlayerScore(T& player)
{
    if (player.score <= 21)
    {
        return true;
    }
    else if ((player.score > 21) && (player.aces == 0))
    {
        return false;
    }
    else
    {
        static constexpr int aceDecrementFactor{ 10 };
        player.score -= aceDecrementFactor;
        return true;
    }
}

bool playerTurn(Dealer& dealer, Player& player, const deck_type& deck, index_type& cardNum)
{
    bool wantsHit{ playerWantsHit() };

    while (wantsHit)
    {
        (player.cards).push_back(deck[cardNum]);
        player.score += getCardValue(deck[cardNum]);
        if (isAce(deck[cardNum]))
        {
            ++(player.aces);
        }
        ++cardNum;
        if (!checkPlayerScore(player))
        {
            displayCardsAndScores(dealer, player);
            return false;
        }
        displayCardsAndScores(dealer, player);
        wantsHit = playerWantsHit();
    }
    return (checkPlayerScore(player));
}

bool dealerTurn(Dealer& dealer, Player& player, const deck_type& deck, index_type& cardNum)
{
    while (dealer.score < 17)
    {
        (dealer.cards).push_back(deck[cardNum]);
        dealer.score += getCardValue(deck[cardNum]);
        if (isAce(deck[cardNum]))
        {
            ++(dealer.aces);
        }
        ++cardNum;
    }
    displayCardsAndScores(dealer, player);
    return checkPlayerScore(dealer);
}

BlackjackResult playBlackjack(const deck_type& deck)
{
    index_type cardNum{ 0 };
    Dealer dealer{ {deck[cardNum]}, getCardValue(deck[cardNum]), static_cast<int>(isAce(deck[cardNum])) }; ++cardNum;
    Player player{ {deck[cardNum], deck[cardNum + 1]}, getCardValue(deck[cardNum]) + getCardValue(deck[cardNum + 1]), static_cast<int>(isAce(deck[cardNum])) }; cardNum += 2;
    displayCardsAndScores(dealer, player);
    
    if (!playerTurn(dealer, player, deck, cardNum))
    {
        return BlackjackResult::dealer_wins;
    }

    else if (!dealerTurn(dealer, player, deck, cardNum))
    {
        return BlackjackResult::dealer_wins;
    }

    else if (player.score > dealer.score)
    {
        return BlackjackResult::player_wins;
    }

    else if (dealer.score > player.score)
    {
        return BlackjackResult::dealer_wins;
    }

    else
    {
        return BlackjackResult::tie;
    }

}