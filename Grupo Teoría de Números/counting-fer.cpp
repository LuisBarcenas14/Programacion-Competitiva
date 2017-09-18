#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

const ll modulo=1000000007;
ll criba[5001];
ll factoriales[5001];
ll comb=1;
void modified_sieve(){
    for(ll i=1;i<5001;i++){
        for(ll j=i+i;j<5001;j+=i)
            criba[j]++;
    }
}

void factorialCalc(){
    //int a;
    factoriales[0]=factoriales[1]=1;
    for(ll i=2;i<5001;i++)
        factoriales[i]=(factoriales[i-1]*i)%modulo;
}

ll exp_rapida(ll a, ll n, ll m){
    ll exp=1;
    ll x=a%m;
    while(n>0 && x>1){
        if(n%2==1)
            exp=((exp%m)*(x%m))%m;
        x=((x%m)*(x%m))%m;
        n/=2;
    }
    return exp%m;
}

ll exp(ll a,ll b,ll c){
    if(b==0)return 1;
    ll dev=exp(a,b>>1,c);
    dev=(dev*dev)%c;
    if(b&1)dev=(dev*a)%c;
    return dev;
}

void combinacion(ll n, ll r){
    ll num=factoriales[n];
    ll den=((factoriales[r]%modulo)*(factoriales[n-r]%modulo))%modulo;
    //ll inverso=exp_rapida(den, modulo-2, modulo);
    ll inverso=exp(den, modulo-2, modulo);
    comb=(comb%modulo)*(((num%modulo)*(inverso%modulo))%modulo);
    comb=comb%modulo;
}

ll resp(ll n, ll k){
    ll ans=0;
    for(ll i=2;i<=n;i++){
        if(criba[i]>k){
            ans+=k;
            combinacion(criba[i], k);
        }
        else
            ans+=criba[i];
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    modified_sieve();
    factorialCalc();
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        ll x=resp(n, k);
        if(comb==0)
            comb++;
        if(x==0)
            comb=0;
        comb=comb%modulo;
        cout<<x<<" "<<comb<<"\n";
        comb=1;
    }
    return 0;
}
