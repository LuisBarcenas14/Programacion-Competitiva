#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int lli;
#define pb push_back
#define endl '\n'
#define MAX 1000001

bool criba [MAX];
vi primos;
lli i,j,p,sum,pt;

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.pb(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
    //for(i=0;i<10;i++){ cout<<primos[i]<<" "; }
    //cout<<endl;
}

lli pf(lli n){
    j=0; p=2;
    sum=0;
    lli on=n,l=0;
    while(p*p<=n && p){
        if(n%p==0){
            pt=1;
            l++;
            while(n%p==0){
                n/=p;
                pt*=p;
            }
            sum+=pt;
        }
        p=primos[++j];
    }
    if(l==1 && n==1){ sum++; }
    if(n!=1){
        if(n==on){ sum++; }
        sum+=n;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    cin.tie(0);
    sieve();
    lli n,k=1;
    while(cin>>n && n){
        cout<<"Case "<<k++<<": ";
        if(n==1){ cout<<"2"<<endl; continue; }
        cout<<pf(n)<<endl;
    }
    return 0;
}

