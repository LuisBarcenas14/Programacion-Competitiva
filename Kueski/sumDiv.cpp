#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef long long ll;
typedef vector<int> vi;
#define endl '\n'
#define pb push_back
#define MAX 46341//31623

vi primos;
bool criba[MAX];
lli i,j,p,x,sum,e;

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.pb(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
}

ll sumDiv(ll N) {
    ll PF_idx = 0, PF = primos[PF_idx], ans = 1;
    // start from ans = 1
    while (PF * PF <= N) {
    ll power = 0;
    while (N % PF == 0) { N /= PF; power++; }
    ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1);
    PF = primos[++PF_idx];
    }
    if (N != 1) ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1); // last
    return ans;
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    lli n;
    while(cin>>n){
        cout<<sumDiv(n)<<endl;
    }
    return 0;
}

