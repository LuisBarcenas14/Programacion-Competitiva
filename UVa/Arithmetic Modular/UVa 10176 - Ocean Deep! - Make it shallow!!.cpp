#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define mod 131071

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    ll r=0;
    char c;
    while(cin>>c){
        if(c=='#'){
            if(r==0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
            r=0;
        }else{
            r = ((r*2)%mod+c-'0')%mod;
        }
    }
    return 0;
}
