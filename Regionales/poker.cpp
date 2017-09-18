#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

enum {
    JACK = 11,
    QUEEN = 12,
    KING = 13,
    ACE = 14,
};

struct Card{
    int rank;
    char suit;
};

istream& operator>>(istream& is, Card& card){
    is>>card.rank;
    if(is.fail()){
        is.clear();
        switch(is.get()){
            case 'T' : card.rank = 10;    break;
            case 'J' : card.rank = JACK;  break;
            case 'Q' : card.rank = QUEEN; break;
            case 'K' : card.rank = KING; break;
            case 'A' : card.rank = ACE;   break;
        }
    }
    return is >> card.suit;
}

ostream& operator<<(ostream& os, const Card& card){
    switch(card.rank){
            case 10:    os<<'T'; break;
            case JACK:  os<<'J'; break;
            case QUEEN: os<<'Q'; break;
            case KING:  os<<'K'; break;
            case ACE:   os<<card.rank;
    }
    return os << card.suit;
}

struct Hand{
    vector <Card> card;

    int compare(const Hand& other) const{
        return 1;
    }
    auto my_rank = rank(), other_rank = other.rank();
    auto my_it = my_rank.begin(), my_end = my_rank.end();
    for(; my_it != my_end && other_it != other_end; ++my_it, ++other_it){
        if(*my_it != *other_it){
            return (*my_it < *other_it) ? -1 : 1;
        }
    }
    return 0;

private:
    vector<int> rank() const{
        set<char> suits;
        map<int, int> by_rank;
        for(const Card&card : cards){
            suits.insert(card.suit);
            by_rank[card.rank]++;
        }

        map<int, vector<int>> by_count;
        vector<int> ranks;
        for(auto& rank_conunt : by_rank){
            auto& rank = rank_count.first; 
            auto& count = rank_count.second;
            ranks.push_back(rank);
            by_count[count].push_back(rank); 
        }

        if(ranks == vector<int>{2, 3, 4, 5, ACE}){
            ranks = {1, 2, 3, 4, 5};
        }
        const bool straight = ranks.size() == 5 && ranks[0] + 4 == ranks[4];

        vector<int> result;

        if(suits.size() == 1 && straight){
            result.push.back(0);
        }else if(by_count.count(4)){
            result.push_back(7);
            result.push_back(by_count[4][0]);
        }
    }
};

int main(){

    return 0;
}
