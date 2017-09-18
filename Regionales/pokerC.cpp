#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

// ----------------------------------------------------------------------------
// Card
// ----------------------------------------------------------------------------

enum {
    JACK  = 11,
    QUEEN = 12,
    KING  = 13,
    ACE   = 14,
};

struct Card {
    int rank;
    char suit;
};

istream& operator>>(istream& is, Card& card) {
    is >> card.rank;
    if (is.fail()) {
        is.clear();
        switch (is.get()) {
            case 'T': card.rank = 10;    break;
            case 'J': card.rank = JACK;  break;
            case 'Q': card.rank = QUEEN; break;
            case 'K': card.rank = KING;  break;
            case 'A': card.rank = ACE;   break;
        }
    }
    return is >> card.suit;
}

ostream& operator<<(ostream& os, const Card& card) {
    switch (card.rank) {
        case 10:    os << 'T'; break;
        case JACK:  os << 'J'; break;
        case QUEEN: os << 'Q'; break;
        case KING:  os << 'K'; break;
        case ACE:   os << 'A'; break;
        default:    os << card.rank;
    }
    return os << card.suit;
}

// ----------------------------------------------------------------------------
// Hand
// ----------------------------------------------------------------------------

struct Hand {
    vector<Card> cards;

    // Compare two hands and return an int similar to strcmp:
    //   this <  other -> -1
    //   this == other ->  0
    //   this >  other ->  1
    int compare(const Hand& other) const {
        auto my_rank = rank(),
             other_rank = other.rank();
        auto my_it = my_rank.begin(),
             my_end = my_rank.end(),
             other_it = other_rank.begin(),
             other_end = other_rank.end();
        for (; my_it != my_end && other_it != other_end; ++my_it, ++other_it) {
            if (*my_it != *other_it) {
                return (*my_it < *other_it) ? -1 : 1;
            }
        }
        return 0;
    }

  private:
    vector<int> rank() const {
        set<char> suits;
        map<int, int> by_rank;
        for (const Card& card : cards) {
            suits.insert(card.suit);
            by_rank[card.rank]++;
        }

        map<int, vector<int>> by_count;
        vector<int> ranks;
        for (auto& rank_count : by_rank) {
            auto& rank = rank_count.first;
            auto& count = rank_count.second;
            ranks.push_back(rank);
            by_count[count].push_back(rank);
        }

        if (ranks == vector<int>{2, 3, 4, 5, ACE}) {
            ranks = {1, 2, 3, 4, 5};
        }
        const bool straight = ranks.size() == 5 && ranks[0] + 4 == ranks[4];

        vector<int> result;

        // royal flush / straight flush
        if (suits.size() == 1 && straight) {
            result.push_back(8);

        // four of a kind
        } else if (by_count.count(4)) {
            result.push_back(7);
            result.push_back(by_count[4][0]);

        // full house
        } else if (by_count.count(3) && by_count.count(2)) {
            result.push_back(6);
            result.push_back(by_count[3][0]);

        // flush
        } else if (suits.size() == 1) {
            result.push_back(5);

        // straight
        } else if (straight) {
            result.push_back(4);

        // three of a kind
        } else if (by_count.count(3)) {
            result.push_back(3);
            result.push_back(by_count[3][0]);

        // two pairs / one pair
        } else if (by_count.count(2)) {
            if (by_count[2].size() == 2) {
                result.push_back(2);
                result.push_back(by_count[2][1]);
                result.push_back(by_count[2][0]);
            } else {
                result.push_back(1);
                result.push_back(by_count[2][0]);
            }

        // high card
        } else {
            result.push_back(0);
        }

        result.insert(result.end(), ranks.rbegin(), ranks.rend());
        return result;
    }
};

istream& operator>>(istream& is, Hand& hand) {
    hand.cards.clear();
    for (int i = 0; i < 5; i++) {
        Card card;
        is >> card;
        hand.cards.push_back(card);
    }
    return is;
}

ostream& operator<<(ostream& os, const Hand& hand) {
    bool first = true;
    for (const Card& card : hand.cards) {
        if (!first) os << ' ';
        os << card;
        first = false;
    }
    return os;
}

// ----------------------------------------------------------------------------

int main() {
    int count;
    cin >> count;
    for (int i = 0; i < count; i++) {
        Hand h1, h2;
        cin >> h1 >> h2;
        switch (h1.compare(h2)) {
            case -1: cout << h2 << '\n'; break;
            case 0:  cout << "Tie\n";    break;
            case 1:  cout << h1 << '\n'; break;
        }
    }
}