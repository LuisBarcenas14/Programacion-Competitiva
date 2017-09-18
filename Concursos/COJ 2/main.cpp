#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define endl '\n'
#define pb push_back
#define MAX  1001
#define mod 1000000007

lli f[MAX];

void genF(){
    f[0]=3;
    f[1]=11;
    for(int i=2;i<MAX;i++){
        f[i]=((2*f[i-1])%mod+(3*f[i-2])%mod)%mod;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    genF();
    int a,t;
    cin>>t;
    while(t--){
        cin>>a;
        cout<<f[a]<<endl;
    }
}
