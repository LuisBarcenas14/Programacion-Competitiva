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

int pf(int a, int c){
    j=0; p=2;
    int e,e2,b=1;
    while(p*p<=c  &&p){
        e=e2=0;
        //cout<<"p: "<<p;
        if(c%p==0){
            while(c%p==0){
                c/=p;
                e++;
            }

        }
        if(a%p==0){
            while(a%p==0){
                a/=p;
                e2++;
            }
        }
        //cout<<" e1: "<<e<<" e2: "<<e2<<endl;
        if(e2>e){ return -1; }
        else{
            if(e2!=e){ b*=pow(p,e); }
        }
        p=primos[++j];
    }
    if(c!=1){
        if(c==a){  }
        else if(a==1){ b*=c; }
        else{ return -1; }
    }
    return b;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    sieve();
    int t,a,c,g,b,r;
    cin>>t;
    while(t--){
        cin>>a>>c;

        if(c%a==0)
            cout<<pf(a,c)<<endl;
        else
            cout<<"NO SOLUTION"<<endl;
    }
    return 0;
}
