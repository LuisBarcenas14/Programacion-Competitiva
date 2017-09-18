#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define endl '\n'
#define MAX 1000010

bool criba[MAX];
lli i,j,n,t;

void sieve(){
    for(i=2;i<MAX;i++) if(!criba[i]){
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
}

void res(){
    bool b=false;
    for(i=1,j=n-1;i<=j;i+=2,j-=2){
        if(criba[i] && criba[j]){ break; }
    }
    if(i>j)
        cout<<"Goldbach's conjecture is wrong."<<endl;
    else
        cout<<n<<" = "<<i<<" + "<<j<<endl;
}

int main(){
    sieve();
    while(cin>>n && n){
        res();
    }
    return 0;
}
