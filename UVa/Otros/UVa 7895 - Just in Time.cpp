#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int lli;
#define endl '\n'
#define MAX 1000001

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

bool isPrime(lli n){
    j=0;p=2;
    while(p*p<=n && p){
        if(n%p==0)
            return false;
        p=primos[++j];
    }
    return true;
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    sieve();
    lli a,k,kt=10;
    //while(cin>>a){
    for(k=2;k<1000000000;k++){
        //if(a<2){ cout<<"0"<<endl; continue; }
        a=k;
        while(!isPrime(a)){
            a--;
        }

        //cout<<a<<endl;
        if(a<kt){ cout<<a<<endl;  }
        kt=a;
    }
    return 0;
}

/*
if(n<MAX){
            k = lower_bound(primos.begin(), primos.end(), n)-primos.begin();
            if(primos[k]>n || primos[k]==0){ k--; }
            cout<<primos[k]<<endl;
        }else{
            while(!isPrime(n)){
                n--;
            }
            cout<<n<<endl;
        }
*/
