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
    while(p<=n &&p){
        tn=n;
        if(d%p==0){
            e=0;
            while(p<=tn && d%p==0){
                tn/=p;
                e+=tn;
            }
            while(e-- && d%p==0){
                d/=p;
            }
            if(d==1){ band=true; break; }
        }
        p=primos[++j];
    }
    //cout<<"d: "<<d<<endl;
    if(p==0){ p=primos[--j]; }
    if(d!=1 && d>p){
        if(d<=n){ band=true; }
    }
    if(band)
        printf(" divides %d!\n",n);
    else
        printf(" does not divide %d!\n",n);
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    sieve();
    int n,d;
    while(cin>>n>>d){
        printf("%d",d);
        if(d==1 || d==0){ printf(" divides %d!\n",n); continue; }
        //if(d==0){ printf(" does not divide %d!\n",n); continue; }
        pf(n,d);
    }
    return 0;
}
