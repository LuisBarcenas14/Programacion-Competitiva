#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define endl '\n'
#define MAX 40000

vi primos;
bool criba[MAX];
ll i,j;

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.push_back(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
    /*for(i=0;i<10;i++)
        cout<<primos[i]<<" ";
    //*/
}

ll gcd(ll a, ll b){
    return b==0 ? a : gcd(b, a%b);
}

ll numDiv(ll N){
    ll j=0, p=primos[j], ans=1;
    while(p*p<=N){
        ll e=0;
        while(N%p==0){ N/=p; e++; }
        ans*=(e+1);
        p=primos[++j];
    }
    if(N!=1) ans*=2;
    return ans;
}

ll elim(ll n, ll k){
    ll j=0, p=primos[j];
    while(p*p<=k){
        ll e=0;
        if(k%p==0){
            while(k%p==0){ k/=p; }
            while(n%p==0){ n/=p; }
        }
        p=primos[++j];
    }
    if(k!=1 && n%k==0){
        while(n%k==0)
            n/=k;
    }
    return n;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    ll t, n,k,g;
    cin>>t;
    while(t--){
        cin>>n>>k;
        g=gcd(n,k);
        if(g!=1)
            n=elim(n,k);
        cout<<numDiv(n)<<endl;
    }
    return 0;
}


