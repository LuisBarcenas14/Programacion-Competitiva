#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl '\n'
#define MAX 10010

bool criba[MAX];
vi primos;
int i,j;

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.push_back(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=1;
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    int n,m,t;
    cin>>t;
    while(t--){
        cin>>n;
        m=n>>1;
        int k = lower_bound(primos.begin(), primos.end(), m)-primos.begin();
        if(primos[k]==m){ k++; }
        cout<<primos[k]<<endl;
    }
    return 0;
}

