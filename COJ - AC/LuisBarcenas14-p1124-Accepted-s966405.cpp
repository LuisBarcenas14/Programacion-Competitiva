#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define MAX 1000010
#define endl '\n'
#define ios ios_base::sync_with_stdio(0); cin.tie(0);

lli i,j;
bool criba[MAX];
vi primos;
int n;
bool band;


void generarPrimos(){
    for(i=2;i<MAX;i++){
        if(!criba[i]){
            primos.push_back(i);
            for(j=i*i;j<MAX;j+=i){
                criba[j]=true;
            }
        }
    }
}

int main(){
    ios;
    //freopen("in.txt","r",stdin);
    generarPrimos();
    while(cin>>n && n){
        band=false;
        int cont=0;
        for(i=3;i<=n/2;i+=2){
            if(!criba[i] && !criba[n-i]){
                cout<<n<<" = "<<i<<" + "<<n-i<<endl;
                band=true;
                break;
            }
        }
        if(!band){ cout<<"Goldbach's conjecture is wrong."<<endl; }
    }
    return 0;
}