#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define MAX 2000010

ll f[MAX];
ll x,y,d;
const int mod=1000000007;

void pre(){
    f[0]=f[1]=1;
    f[2]=2;
    for(ll i=3;i<MAX;i++){
        f[i]=(i*f[i-1])%mod;
    }
}


void extendedEuclid(ll a, ll b){
    if(b==0){ d=a; x=1; y=0; return;}
    extendedEuclid(b, a%b);
    ll x1=y;
    ll y1=x-(a/b)*y;
    x=x1;
    y=y1;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    pre();
    int n;
    cin>>n;
    ll ans,num,den;
    den= ( (f[n]*f[n])%mod *(n+1) )%mod;
    extendedEuclid(den, mod);
    x = (x+mod)%mod;
    num = f[2*n];
    ans = (num*x)%mod;
    cout<<ans<<endl;
}
