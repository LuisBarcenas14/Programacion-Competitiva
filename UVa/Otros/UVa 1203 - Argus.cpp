#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define mp make_pair
typedef pair<int, int> ii;

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
int Q_num[3001];


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    string s;
    int q,p,k,pq_f,pq_s;
    while(cin>>s && s!="#"){
        cin>>q>>p;
        pq.push(mp(p,q));
        Q_num[q]=p;
    }
    cin>>k;
    while(k--){
        pq_f = pq.top().first;
        pq_s = pq.top().second;
        //cout<<pq_f<<" "<<pq_s<<endl;
        cout<<pq_s<<endl;
        pq.pop();
        pq.push( mp( pq_f+Q_num[pq_s], pq_s) );
    }
    return 0;
}


