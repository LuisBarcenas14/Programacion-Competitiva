#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 1010

bool criba[MAX];
vector<int> primos;
vector<int> sd;

int sumaD(int n){
    if(n>=100){
        return (n/100)+(n/10 % 10) + (n%10);
    }
    if(n>=10)
        return (n/10 % 10) + (n%10);
    if(n<10)
        return (n%10);
}

void sieve(){
    int i,j;
    for(i=2; i<MAX; i++)if(!criba[i]){
        primos.push_back(i);
        if(sumaD(i)==14)
            sd.push_back(i);
        for(j=i*i; j<MAX; j+=i)
            criba[j]=true;
    }
    for(int i=0; i<(int)sd.size(); i++)
        cout<<sd[i]<<" ";
    cout<<endl;
}

int main(){
    sieve();
    return 0;
}
