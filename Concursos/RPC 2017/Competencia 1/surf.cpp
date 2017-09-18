#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii, int> iii;
typedef vector<iii> viii;

#define minu waves[i].first.first
#define fun waves[i].first.second
#define wait waves[i].second
#define pb push_back
#define mp make_pair
#define endl '\n'

int i,j,n,a,b,c;
viii waves;

bool ord(iii a, iii b){
    return a.first.first<b.first.first;
}

int main(){
    freopen("in","r",stdin);
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a>>b>>c;
        waves.pb(mp(mp(a,b),c));
    }
    sort(waves.begin(), waves.end(), ord);
    queue<ii> pend;
    queue<int> t;
    t.push(10);
    t.front()+=5;
    cout<<"**"<<t.front()<<endl;
    for(i=0;i<n;i++){

    }
    return 0;
}
