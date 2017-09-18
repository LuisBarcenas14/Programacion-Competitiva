#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int nums[10];
ll g;

void res(ll n, ll g){
    ll sum=0, GCD;
    for(int i=0;i<n;i++){
        sum += g/nums[i];
    }
    g=n*g;

    GCD = __gcd(sum, g);
    sum/=GCD;
    g/=GCD;

    cout<<g<<"/"<<sum<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    ll t,n;
    cin>>t;
    for(int j=1; j<=t; j++){
        cin>>n;
        g=1;
        cout<<"Case "<<j<<": ";
        for(int i=0;i<n;i++){
            cin>>nums[i];
            g*=nums[i];
        }
        res(n, g);
    }
    return 0;
}
