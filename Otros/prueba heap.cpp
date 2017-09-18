#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define mp make_pair
typedef pair<int, int> ii;
//priority_queue<int, vector<int>, greater<int> > pq;
/*
struct compare{
    bool operator() (const ii &a, const ii &b){
        if(a.first==b.first)
            return a.second>b.second;
        return a.first>b.first;
    }
};
*/

priority_queue<ii, vector<ii>, greater<ii> > pq;

int main(){
    pq.push(mp(5,2));
    pq.push(mp(10,5));
    pq.push(mp(10,6));
    pq.push(mp(3,1));
    while(!pq.empty()){
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }
    return 0;
}

/*
    pq.push(5);
    pq.push(10);
    pq.push(4);
    pq.push(3);
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
*/
