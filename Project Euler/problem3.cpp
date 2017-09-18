#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int MAX = 1000000;
ll s=0;
int a,b,t;
ll i,j;
bool criba[MAX];
vector<int> primos;

void sieve(){
    for(i=2; i<MAX; i++)if(!criba[i]){
        primos.push_back(i);
        for(j=i*i; j<MAX; j+= i)
            criba[j]=true;
    }
}

ll lastPf(ll n){
    int j=0, p=2, u;
    while(p*p<=n && p){
        u=p;
        while(n%p==0)n/=p;
        p=primos[++j];
    }
    if(n!=1) u=n;
    return u;
}

int main(){
    //freopen("in","r",stdin);
    freopen("out","w",stdout);
    sieve();
    ll n=600851475143;
    cout<<lastPf(n)<<endl;
}


