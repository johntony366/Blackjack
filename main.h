#pragma once
#include <array>
#include <vector>

enum class CardRank : int
{
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,
    rank_ace,

    max_ranks
};

enum class CardSuit : int
{
    club,
    diamond,
    heart,
    spade,

    max_suits
};

enum class BlackjackResult : int
{
    player_wins,
    dealer_wins,
    tie
};

struct Card
{
    CardRank cardRank{ };
    CardSuit cardSuit{ };
};

struct Player
{
    std::vector<Card> cards{ };
    int score{ };
    int aces{ };
};

struct Dealer
{
    std::vector<Card> cards{ };
    int score{ };
    int aces{ };
};

using deck_type = std::array<Card, 52>;
using cards_type = std::vector<Card>;
using index_type = deck_type::size_type;