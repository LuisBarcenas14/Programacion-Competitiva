#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int x,y,d;

ll lastNonZero(ll n, ll m){
    ll i=n-m+1, j=n,ans=1;
    while(i<=j){
        ans*=j;
        while(ans%10==0){
            ans/=10;
        }
        ans=(ans%1000000000);
        --j;
    }
    return ans%10;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    ll a,b;
    while(cin>>a>>b){
        if(b==0){ cout<<"1\n"; continue; }
        cout<<lastNonZero(a,b)<<endl;
    }
    return 0;
}
