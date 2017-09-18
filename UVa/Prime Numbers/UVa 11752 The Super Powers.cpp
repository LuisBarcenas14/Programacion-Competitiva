#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<ulli> vulli;
#define endl '\n'

bool visitado[(1<<16)+2];
vulli res;

ulli i,j,jl,p,k,it;

bool criba[65];
set<ulli> s0;

void sieve(){
    int i,j;
    for(i=2;i<65; i++)if(!criba[i]){
        for(j=i*i;j<65;j+=i)
            criba[j]=true;
    }
    /*for(i=2;i<64;i++){
        if(!criba[i]) cout<<i<<" ";
    }
    cout<<endl;*/
}

ulli pot(ulli n, ulli e){
    ulli r=1,b=n;
    while(e--){
        r*=b;
    }
    return r;
}

void super(){
    j=pot(2, 64)-1;
    jl=(ulli)sqrt(j);
    jl=(ulli)sqrt(jl);
    //cout<<jl<<" "<<(1<<16)<<endl;
    ///*
    for(i=2;i<jl;i++){
        //cout<<"i: "<<i<<endl;
        for(j=4;j<64;j++){
            if(criba[j] && j*log2(i)<64){
                s0.insert(pot(i,j));
            }
        }

    }
    s0.insert(1);
    for(set<ulli>::iterator i=s0.begin();i!=s0.end(); i++){
        cout<<*i<<endl;
    }
    //*/
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    super();
    return 0;
}

;
