#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const ll modulo=1000000007;
ll criba[5001];
ll factoriales[5001];
ll comb=1;
ll x, y, d;

void modified_sieve(){
    for(ll i=1;i<5001;i++){
        for(ll j=i+i;j<5001;j+=i)
            criba[j]++;
    }
}

void factorialCalc(){
    factoriales[0]=factoriales[1]=1;
    for(ll i=2;i<5001;i++)
        factoriales[i]=(factoriales[i-1]*i)%modulo;
}
void extendedEuclid(ll a, ll b){
    if(b==0){ x=1; y=0; d=a; return; }
    extendedEuclid(b, a%b);
    ll x1=y;
    ll y1=x-(a/b)*y;
    x=x1;
    y=y1;
}

void combinacion(ll n, ll r){
    ll num=factoriales[n];
    //cout<<"numerador: "<<num<<"\n";
    ll den=((factoriales[r]%modulo)*(factoriales[n-r]%modulo))%modulo;
    //cout<<"denominador: "<<den<<"\n";
    extendedEuclid(den, modulo);
    x=(x+modulo)%modulo;
    comb=((comb%modulo)*(((num%modulo)*(x%modulo)))%modulo);
    //cout<<"combinacion: "<<comb<<"\n";
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