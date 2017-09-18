#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define endl '\n'
#define MAX 40000

vi primos;
bool criba[MAX];
ll i,j;

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.push_back(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
    /*for(i=0;i<10;i++)
        cout<<primos[i]<<" ";
    //*/
}

ll numPF(ll N){
    ll j=0, p=primos[j], ans=0;
    while(p*p<=N){
        if(N%p==0 && p){
            while(N%p==0){ N/=p; }
            ans++;
        }
        p=primos[++j];
    }
    if(N!=1){ ans++; }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("in","r",stdin);
    sieve();
    ll t,n,a,c,pf,sum;
    int b=0;
    cin>>t;
    while(t--){
        cin>>n;
        sum=b=0;
        for(int i=0;i<n;i++){
            cin>>a;
            pf=numPF(a);
            //cout<<"pf: "<<a<<" - "<<pf<<" ";
            sum=(sum+pf)%2;
        }
        if(sum==1){ //pf es impar
            cout<<"Poo\n"; //b^=1;
        }else{
            cout<<"Mak\n";
        }
    }
    return 0;
}


