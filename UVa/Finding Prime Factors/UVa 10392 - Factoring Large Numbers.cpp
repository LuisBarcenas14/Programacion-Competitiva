
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<lli> vi;
#define endl '\n'
#define MAX 1000010

bool criba[MAX];
lli i,j,p;
vi primos;

void sieve(){
    for(i=2;i<MAX;i++) if(!criba[i]){
        primos.push_back(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }

}

void pf(lli n){
    j=0;
    p=primos[j];
    while(p<=n && j<primos.size()){
        while(n%p==0){
            cout<<"    "<<p<<endl;
            n/=p;
        }
        p=primos[++j];
    }

    if(n!=1){ cout<<"    "<<n<<endl; }
    cout<<endl;
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    sieve();
    //cout<<"complete"<<endl;
    lli n;

    while(cin>>n && n!=-1){
        pf(n);
    }
    return 0;
}

