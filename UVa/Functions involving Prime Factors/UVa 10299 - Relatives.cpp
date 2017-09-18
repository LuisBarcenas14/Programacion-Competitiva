#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define endl '\n'
#define pb push_back
#define MAX 31623

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

lli EulerPhi(lli n){
    j=0; p=2;
    lli ans=n;
    while(p*p<=n && p){
        if(n%p==0) ans-=ans/p;
        while(n%p==0) n/=p;
        p=primos[++j];
    }
    if(n!=1) ans-=ans/n;
    return ans;
}



int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    lli n;
    while(cin>>n && n){
        if(n==1){ cout<<"0"<<endl; continue; }
        cout<<EulerPhi(n)<<endl;
    }
    return 0;
}
