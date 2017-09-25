#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

string c="cloudy", s="sunny", r="rainy";

int main(){
    //freopen("in-av","r",stdin);
    int t;
    cin>>t;
    ll a, b,x ,v, bit;
    while(t--){
        cin>>b>>x;
        if(x>29){ cout<<"-1"<<endl; continue; }
        bit = 1L<<x;
        if(b-bit > 0)
            a = b-bit;
        else
            a = b+bit;
        if(a<=10e9)
            cout<<a<<endl;
        else
            cout<<"-1"<<endl;
    }
}
