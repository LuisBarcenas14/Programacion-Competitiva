#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int main(){
    ll x,k,t;
    cin>>t;
    while(t--){
        cin>>x>>k;
        if(k%2==0){
            cout<<(k/2)<<" "<<(k/2)<<endl;
        }else{
            cout<<(k/2)<<" "<<(k/2+1)<<endl;
        }
        /*
        if(k>0)
            cout<<"1 "<<(k-1)<<endl;
        else if (k<0)
            cout<<"-1 "<<(k+1)<<endl;
        */
    }
    return 0;
}
