#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int lli;
#define endl '\n'
#define MAX 10000010

bool criba[MAX];
vi primos;
lli i,j;

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
    bool b;
    while(cin>>n && n){
        cout<<n<<":\n";
        b=false;
        if(n%2==1){
            if(!criba[n-2]){
                i=2; j=n-2;
                b=true;
            }
        }else{
            for(i=3,j=n-3;i<=j;i+=2,j-=2){
                if(!criba[i]&&!criba[j]){
                    b=true; break;
                }
            }
        }
        if(n==4){ b=true; i=2; j=2; }
        //cout<<"---"<<i<<" "<<j<<endl;
        if(b){
            cout<<i<<"+"<<j<<endl;
        }else{
            cout<<"NO WAY!"<<endl;
        }

    }
    return 0;
}

