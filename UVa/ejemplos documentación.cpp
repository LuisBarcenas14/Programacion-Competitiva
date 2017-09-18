#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void divisores1(int n){
    for(int i=1; i<=n; i++){
        if(n%i==0)
            cout<<i<<" ";
    }
    cout<<endl;
}

void divisores2(int n){
    for(int i=1; i*i<=n; i++){
        if(n%i==0)
            cout<<i<<" "<<n/i<<" ";
    }
    cout<<endl;
}

void criba(int n){
    bool criba[n+1];
    for(int i=2;i<=20;i++){ criba[i]=false; }
    for(int i=2;i<=20;i++){
        if(!criba[i]){
            cout<<i<<" ";
            for(int j=i*i;j<=n;j+=i)
                criba[j]=true;
        }
    }
    cout<<endl;
}

int main(){
    int n;
    while(cin>>n){
        criba(n);
    }
    return 0;
}
