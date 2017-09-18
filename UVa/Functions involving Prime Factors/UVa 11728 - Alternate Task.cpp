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

lli sumDiv(lli n){
    lli j=0,p=2,ans=1,e;
    while(p*p<=n && p){
        e=0;
        while(n%p==0){ n/=p; e++; }
        ans*=((lli)pow((double)p,e+1.0)-1)/(p-1);
        p=primos[++j];
    }
    if(n!=1){ ans*=((lli)pow((double)n,2.0)-1)/(n-1); }
    return ans;
}

int res[1001];

void preCal(){
    for(int i=1;i<=1000;i++){ res[i]=-1; }
    res[1]=1;
    for(int i=2;i<1000;i++){
        lli r = sumDiv(i);
        if(r<1001){ res[r]=i; }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    preCal();
    int n,k=1;
    while(cin>>n && n){
        cout<<"Case "<<k++<<": ";
        cout<<res[n]<<endl;
    }
    return 0;
}

