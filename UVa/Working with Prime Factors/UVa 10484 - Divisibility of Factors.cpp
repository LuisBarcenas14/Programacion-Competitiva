#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int lli;
#define endl '\n'
#define MAX 1000010

bool criba[MAX];
lli i,j,p;
vi primos;

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.push_back(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }

    //for(i=2;i<10;i++){ cout<<primos[i]<<" "; }
    //cout<<endl;
}


void pf(int n, int d){
    bool band=false;
    j=0,p=2;
    int tn,e;
    long long ans=1;
    while(p<=n &&p){
        tn=n;
        e=0;
        while(p<=tn || d%p==0){
            tn/=p;
            e+=tn;
            if(d%p==0){ e--; d/=p; }
        }
        if(e<0){ ans=0; break; }
        ans*=(e+1);

        p=primos[++j];
    }
    //cout<<"d: "<<d<<endl;
    //if(p==0){ p=primos[--j]; }
    p=primos[--j];
    //if(n==3){ cout<<"N: "<<n<<" d: "<<d<<" "<<p<<"-";}
    if(d!=1 && d>p){

        if(d<=n){ ans*=2; }else{ ans=0; }
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    sieve();
    int n,d;
    while(cin>>n>>d && d){
        if(n==0 || n==1){ if(d==1){ cout<<"1"<<endl; }else{ cout<<"0"<<endl; } continue; }
        pf(n,d);
    }
    return 0;
}
