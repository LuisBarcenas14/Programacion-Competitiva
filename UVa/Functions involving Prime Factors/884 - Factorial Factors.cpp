#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define endl '\n'
#define pb push_back
#define MAX 1000001


bool criba[MAX];
vi primos;
lli i,j,p,sum,e;
int ans[1000001];

void sieve(){
    criba[1]=true;
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.pb(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
    //for(i=0;i<10;i++){ cout<<primos[i]<<" "; }
}

void PreNumPF(){
    ans[1]=0;
    for(i=2;i<MAX;i++){
        j=0; p=2;
        lli n=i;
        ans[i]=ans[i-1];
        while(criba[n] && n>1){
            while(n%p==0){ n/=p;  ans[i]++; }
            p=primos[++j];
        }
        if(!criba[n]){ ans[i]++; }
    }
}


int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    sieve();
    PreNumPF();
    lli n;
    while(cin>>n){
        cout<<ans[n]<<endl;
    }
    return 0;
}
