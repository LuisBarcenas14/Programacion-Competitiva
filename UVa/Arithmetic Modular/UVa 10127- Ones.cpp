#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int howOnes(int n){
    int i=2,mod=11%n;
    while(mod!=0){
        mod=( (mod*10)+1 )%n;
        i++;
    }
    return i;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin>>n){
        if(n==0 || n==1){ cout<<"1\n"; continue; }
        cout<<howOnes(n)<<endl;
    }
    return 0;
}
