#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<ll, ll> lll;
typedef vector<lll> vlll;
#define endl '\n'

const int MAX = 450;
const ll LIM = 12158598919;

bool criba[MAX];
vi primos;
vlll eu;

void sieve(){
    ll i,j;
    for(i=2; i<MAX; i++)if(!criba[i]){
        primos.push_back(i);
        for(j=i*i; j<MAX; j+=i)
            criba[j]=true;
    }
    //for(int i=0; i<10; i++)
    //    cout<<primos[i]<<" ";
}


ll EulerPhi(ll n){
    ll j=0, p=primos[j], ans=n;
    while(p*p<=n){
        if(n%p==0) ans-=ans/p;
        while(n%p==0)n/=p;
        p=primos[++j];
    }
    if(n!=1) ans-=ans/n;
    return ans;
}

void pre(){
    ll acum=0, i;
    //eu.push_back(lll(0, 0));
    for(i=2; acum<=LIM; i++){
        acum+=EulerPhi(i);
        eu.push_back(lll(acum, i));
    }
    //cout<<"llego hasta "<<eu[i-2].first<<" - "<<eu[i-2].second<<endl;
}

bool cmp(const lll &f, const lll &s){
    return f.first<s.first;
}

void res(ll n){
    ll pre, act, res,j;
    int i = lower_bound(eu.begin(), eu.end(), lll(n, 0), cmp)-eu.begin();
    //cout<<eu[i].second<<endl;
    pre=eu[i-1].first;
    act=eu[i  ].first;
    n-=pre;
    j=1;
    //cout<<"n: "<<n<<" ";
    while(n){
        if(__gcd(j++, eu[i].second) == 1)
            n--;
    }
    cout<<--j<<"/"<<eu[i].second<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in", "r", stdin);
    sieve();
    pre();
    ll n;
    while(cin>>n){
        if(n==1)
            cout<<"0/1\n";
        else if(n==2)
            cout<<"1/1\n";
        else
            res(n-2);
    }
    return 0;
}
