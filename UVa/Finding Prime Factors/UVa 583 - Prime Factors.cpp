#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define endl '\n'
#define MAX 100000

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

vi pf(int n){
    j=0;
    p=primos[j];
    vi v;
    while(p*p<=n && p){
        while(n%p==0){
            v.push_back(p);
            n/=p;
        }
        p=primos[++j];
    }
    if(n!=1){ v.push_back(n); }

    return v;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    int n;
    bool b;
    while(cin>>n && n){
        vi v; b=false;
        cout<<n<<" = ";
        if(n<0){ b=true; cout<<"-1"; n*=-1; }
        v = pf(n);
        for(i=0;i<v.size();i++){
            if(!b){
                cout<<v[i];
                b=true;
            }else{
                cout<<" x "<<v[i];
            }
        }
        cout<<endl;
    }


    return 0;
}

