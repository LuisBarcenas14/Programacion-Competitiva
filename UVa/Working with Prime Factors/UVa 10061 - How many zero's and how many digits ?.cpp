#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define pb push_back
#define endl '\n'
#define MAX 1000010

lli i,j,z,d;
vi primos;

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.pb(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
}

int main(){
    //sieve();
    //cout<<primos.size();
    return 0;
}



