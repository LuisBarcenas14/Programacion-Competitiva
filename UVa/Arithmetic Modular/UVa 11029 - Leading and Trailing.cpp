#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

char s[1000000];

ll mod=1000;

int firstDigits(ll n, ll e){
    ll x;
    double b=e*log(n)/log(10);
    n =(ll)b;
    x=n-2;
    if(b>2){ b-=x; }
    double r=exp(b*log(10));
    return (int)r;
}

int bigmod(int n, int k){
    ll ans=1,i=1,t=n%mod;//t=n^i % mod
    while(i<=k){
        if(k&i){
            ans=(ans*t)%mod;
        }
        t=(t*t)%mod;
        i<<=1;
    }
    return (int)ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    ll t,n,k,ans;
    cin>>t;
    while(t--){
        cin>>n>>k;

        printf("%03d...%03d\n",firstDigits(n,k),bigmod(n,k) );

    }
    return 0;
}

