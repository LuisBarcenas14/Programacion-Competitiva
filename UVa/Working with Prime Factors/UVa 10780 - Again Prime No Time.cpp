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
    //Scout<<endl;
}

int pow(int n, int e){
    int r=1;
    while(e--){
        r*=n;
    }
    return r;
}

int pf(int n, int f){
    j=0; p=2;
    int e,en,mini=1<<31-1;
    int of=f;
    while(p*p<=n  &&p){
        //cout<<"p: "<<p<<" ";
        e=en=0;
        f=of;
        if(n%p==0){
            while(p<=f){
                f/=p;
                e+=f;
            }

            while(n%p==0){
                n/=p;
                en++;
            }
            //cout<<" e1: "<<e<<" e2: "<<en<<endl;
            e/=en;
            if(e==0){ return -1; }
            if(e<mini){ mini=e; }
        }
        p=primos[++j];
    }
    if(n!=1){
        if(n>of){ return -1; }
        f=of;
        e=0;
        while(n<=f){
            f/=n;
            e+=f;
        }
        if(e<mini){ mini=e; }
    }
    return mini;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    sieve();
    int n,f,t,r;
    cin>>t;
    for(int k=1;k<=t;k++){

        cin>>n>>f;
        cout<<"Case "<<k<<":\n";
        if(f==1){
            if(n==1){ cout<<"1"<<endl; }else { cout<<"0"<<endl; }
            continue;
        }
        r=pf(n,f);
        if(r==-1)
            cout<<"Impossible to divide"<<endl;
        else
            cout<<r<<endl;
    }
    return 0;
}
