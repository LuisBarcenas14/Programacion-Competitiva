#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll bigmod(ll n, ll e, ll mod){
    ll i=1,ans=1,t=n%mod; //t= pow(n, i) % mod
    while(i<=e){
        if(i&e){
            ans=(t*ans)%mod;
        }
        t=(t*t)%mod;
        i<<=1;
    }
    return ans;
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(NULL);
    ll n,e,mod;
    while(cin>>n){
        cin>>e>>mod;
        cout<<bigmod(n,e,mod)<<endl;
    }
    return 0;
}
