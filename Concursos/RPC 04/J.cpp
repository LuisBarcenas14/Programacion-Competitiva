#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define MAX 1000010
#define mod 1000000007

ll pot2[MAX];
ll arrS[MAX];
ll i,j;
vector<int> primos;
int criba[MAX];
ll cribaSum[MAX];

void sieve(){
    criba[0]=criba[1]=0;
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.push_back(i);
        for(j=i; j<MAX; j+=i)
            ++criba[j];
    }
    //for(int i=0;i<13;i++)
   //     cout<<"i: "<<i<<" - "<<criba[i]<<endl;
}

void pre(){
    pot2[0]=1;
    pot2[1]=2;
    arrS[0]=1;
    arrS[1]=3;
    cribaSum[0]=cribaSum[1]=0;
    for(int i=2; i<MAX; i++){
        pot2[i]=(pot2[i-1] * 2)%mod;
        cribaSum[i]=(cribaSum[i-1] + criba[i])%mod;
        //arrS[i]=(arrS[i-1]+arr[i])%mod;
        //if(arr[i]<0){ cout<<"WA: "<<i<<" "; }
    }
}

/*
ll pfs(int &n, vector<int> &factors, int x, int y, int dif){
    int j=0, p=primos[0], ans=0;
    ll r=0;
    while(p*p <= n && p){
        if(p>=x && n%p==0){
            ans++;
            //factors.push_back(p);
            r = (r+arr[dif])%mod;
        }
        while(n%p==0) n/=p;
        p=primos[++j];
    }
    if(n!=1 && n>=x){ r = (r+arr[dif])%mod; ans++; }//factors.push_back(n);}
    return r;
}
*/
ll res(int dif){
    ll r=0;
    //cout<<"dif: "<<dif<<" pot2: "<<pot2[dif-1]<<" cribaSum: "<<cribaSum[dif]<<endl;
    r = (pot2[dif-1] * cribaSum[dif])%mod;
    return r;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("K.in","r",stdin);
    sieve();
    pre();
    int n,x,y,p,dif,l,a,b;
    ll r;
    bool band;
    while(cin>>n>>x>>y && (n || x || y)){
        //vector<int> factors;
        dif=p=y-x;

        //r=pfs(p, factors, x, y, dif-1);
        //cout<<"- p: "<<p<<" op: "<<op<<" band: "<<band<<endl;
        /*r=0;
        for(int i=0; i<l && p<y; i++){
            p=factors[i];
            if(p>=x){
                //cout<<"p: "<<p<<" a: "<<arr[dif]<<endl;
                r = (r+arr[dif--])%mod;
            }
            //cout<<"r- "<<r<<endl;
            //cout<<factors[i]<<endl;
        }*/
        cout<<res(dif)<<endl;
    }
    return 0;
}


//5848
