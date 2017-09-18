#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define endl '\n'
#define pb push_back
#define MAX 46341//31623

vi primos;
bool criba[MAX];
lli i,j,p,x,sum,e;

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.pb(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
}

lli numPF(lli n){
    j=0, p=2;
    lli ans=0;
    while(p*p<=n && p){
        while(n%p==0){ n/=p; ans++; }
        p=primos[++j];
    }
    if(n!=1) ans++;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    lli n,pf,m,cont,a,raiz;
    while(cin>>n){
        cont=0;
        while(n--){
            cin>>a;
            pf=numPF(a);
            raiz=lli(sqrt(double(a)));
            //cout<<a<<": "<<d<<endl;
            if(pf==2){ cont++; }
        }
        cout<<cont<<endl;
    }
    return 0;
}
