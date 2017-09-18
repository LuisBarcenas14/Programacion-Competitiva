#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define endl '\n'
#define MAX 54

lli f[MAX];
lli t,n,i;

void fib(){
    f[0]=1;
    f[1]=2;
    for(i=2;i<MAX;i++){
        f[i]=f[i-1]+f[i-2];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fib();
    cin>>t;
    for(int k=1;k<=t;k++){
        cin>>n;
        cout<<"Scenario #"<<k<<":\n";
        cout<<f[n]<<endl<<endl;
    }
    return 0;
}

