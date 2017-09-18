#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define endl '\n'
#define pb push_back
#define MAX 1415
#define MAXN 2000001

bool criba[MAX];
int SODF[MAXN];
lli AcSODF[MAXN];
int phi[MAXN];
lli i,j,p,sum;
vi primos;

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.pb(i);
        SODF[i]=i-1;
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
}

int EulerPhi(int n){
    lli j=0,p=2,ans=n;
    while(p*p<=n &&p){
        if(n%p==0)ans-=ans/p;
        while(n%p==0) n/=p;
        p=primos[++j];
    }
    if(n!=1) ans-=ans/n;
    return ans;
}

int found(int n){
    if(SODF[n]!=-1){
        return SODF[n];
    }else{
        if(phi[n]==0 && n!=1)
            phi[n]=EulerPhi(n);
        return SODF[n]=1+found(phi[n]);
    }
}

void preCal(){
    for(int i=0;i<MAXN;i++){ SODF[i]=-1; }
    SODF[1]=0;
    SODF[2]=1;
    AcSODF[2]=1;
    for(int i=3;i<MAXN;i++){
        SODF[i]=found(i);
        AcSODF[i]=SODF[i]+AcSODF[i-1];
        //SODF[i]=EulerPhi(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    preCal();
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    //cout<<"end"<<endl;
    int m,n,t;
    cin>>t;
    while(t--){
        cin>>m>>n;
        //printf("%8d%8d%8d\n",n,mu[n],M[n]);
        cout<<AcSODF[n]-AcSODF[m-1]<<endl;
    }
    return 0;
}
