#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    int b,q,t,g,l,ans;
    freopen("tor-in","r",stdin);
    //freopen("out","w",stdout);
    while(cin>>b>>q && b){
        while(q--){
            cin>>t;
            g = __gcd(b, t);
            l = b / g * t;
            ans = l / t;
            cout<<ans<<endl;
        }
    }
}
