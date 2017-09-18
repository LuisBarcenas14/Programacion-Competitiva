#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl '\n'
typedef long long ll;

const int MAX = 1000010;

bool criba[MAX];
vi primos;

void sieve(){
    ll i, j;
    for(i=2; i<MAX; i++)if(!criba[i]){
        primos.push_back(i);
        for(j=i*i; j<MAX; j+=i)
            criba[j]=true;
    }
}

ll sumDiv(ll n){
    ll j=0, ans=1, p=primos[j], e;
    while(n%2 == 0) n/=2;
    while(p*p<=n){
        e=0;
        while(n%p==0){ n/=p; e++; }
        ans *= ((ll)pow((double)p, e+1.0)-1) /  (p-1);
        p =primos[++j];
    }
    if(n != 1) ans *= ((ll)pow((double)n, 2.0)) /  (n-1);
    return ans;
}

int main(){
    sieve();
    ll n, c=0,a;
    cin>>n;
    while(n--){
        cin>>a;
        c += sumDiv(a);
    }
    cout<<c<<endl;
    return 0;
}
