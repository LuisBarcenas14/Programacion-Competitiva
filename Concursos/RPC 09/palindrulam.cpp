#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    ll n,s,a;
    int i,j,k;


    while(cin>>n>>s){
        ll t=0;
        bool b=false;
        deque<ll> q;
        for(i=1; i<=n; i++){
            cin>>a;
            q.push_back(a);
            t+=a;
            while(t>s){
                t-=q.front();
                q.pop_front();
            }
            if(t==s && !b){
                j=i;
                k=j-q.size()+1;
                b=true;
                //break;
            }

        }
        if(b)
            cout<<k<<" "<<j<<endl;
        else
            cout<<"-1"<<endl;
    }
    return 0;
}
