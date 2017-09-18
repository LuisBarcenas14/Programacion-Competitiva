#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define endl '\n'
#define MAX 1000010

bool criba[MAX];
lli i,j,n,t;

void sieve(){
    criba[1]=true;
    for(i=2;i<MAX;i++) if(!criba[i]){
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
}

int res(){
    int k=0;
    for(i=1,j=n-1;i<=j;i+=2,j-=2){
        if(!criba[i] && !criba[j]){ k++; }
    }
    return k;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    sieve();
    while(cin>>n && n){
        if(n==4)
            cout<<"1\n";
        else
            cout<<res()<<endl;
    }
    return 0;
}

