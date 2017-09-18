#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define endl '\n'
#define pb push_back
#define mk make_pair
#define MAX 1415

bool criba[MAX];
vii pares;
lli i,j,p,sum,e,r;
vi primos;

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.pb(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
}

lli numPF(lli n){
    lli j=0,p=2,ans=0,e;
    while(p*p<=n && p){
        while(n%p==0){ n/=p; ans++; }
        p=primos[++j];
    }
    if(n!=1){ ans++; }
    return ans;
}


void preCal(){
    pares.pb(mk(1,0));
    for(i=2;i<=2000000;i++){
        pares.pb(mk(i,numPF(i)));
    }
}

bool ord(ii a, ii b){
    if(a.second==b.second)
        return a.first<b.first;
    return a.second<b.second;
}

int main(){
    sieve();
    preCal();
    sort(pares.begin(), pares.end(), ord);
    int n,k=1;
    while(cin>>n && n){
        cout<<"Case "<<k++<<": ";
        cout<<pares[n-1].first<<endl;
    }
    return 0;
}
