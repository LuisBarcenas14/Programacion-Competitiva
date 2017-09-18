#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define endl '\n'
#define pb push_back
#define MAX 1001
#define MAXN 1000001

bool criba[MAX];
int mu[MAXN];
int M[MAXN];
lli i,j,p,e,sum;
vi primos;

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.pb(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
}

int pf(lli n){
    lli j=0,p=2,ans1=0,ans2=0,e;
    while(p*p<=n && p){
        if(n%p==0){
            ans1++;
            while(n%p==0){
                n/=p;
                ans2++;
            }
        }
        p=primos[++j];
    }
    if(n!=1){ ans1++; ans2++; }
    if(ans1!=ans2){
        return 0;
    }else{
        if(ans1%2==0)
            return 1;
        else
            return -1;
    }

}

void preCal(){
    M[1]=mu[1]=1;
    for(int i=2;i<MAXN;i++){
        mu[i]=pf(i);
        M[i]=M[i-1]+mu[i];
    }
}

int main(){
    sieve();
    preCal();
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int n;
    while(cin>>n && n){
        printf("%8d %8d %8d\n",n,mu[n],M[n]);
    }
    return 0;
}
