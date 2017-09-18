#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define endl '\n'
#define pb push_back
#define MAX 31623//1000000000


bool criba[MAX];
vi primos;
lli i,j,p,sum,e;

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.pb(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
    //for(i=0;i<10;i++){ cout<<primos[i]<<" "; }
}

lli numDiv(lli n){
    j=0; p=2;
    lli ans=1;
    while(p*p<=n && p){
        e=0;
        while(n%p==0){ n/=p;  e++; }
        ans*=(e+1);
        p=primos[++j];
    }
    if(n!=1) ans*=2;
    return ans;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    sieve();
    lli t,l,u,maxi=0,maxiL,r;
    cin>>t;
    while(t--){
        maxi=0;
        cin>>l>>u;
        cout<<"Between "<<l<<" and "<<u<<", ";
        while(l<=u){
            r=numDiv(l);
            //cout<<"l: "<<l<<" "<<r<<endl;
            if(r>maxi) {maxi=r; maxiL=l;}
            l++;
        }
        cout<<maxiL<<" has a maximum of "<<maxi<<" divisors."<<endl;
    }
    return 0;
}
