#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const ll mod = 13;

ll modPowNoob(ll n, ll e){
    ll b=n%mod, r=1;
    while(e--){
        r = (r*b)%mod;
    }
    return r;
}

ll modPow(ll n, ll e){
    ll b=n%mod, r=1, i=1;
    while(i<=e){
        if(i&e){
            r = (r*b) % mod;
        }
        b = (b*b) % mod;
        i<<=1;
    }
    return r;
}

int x,y,d;

// store x, y, and d as global variables
void extendedEuclid(int a, int b) {
    if (b == 0) { x = 1; y = 0; d = a; return; }
    // base case
    extendedEuclid(b, a % b);
    // similar as the original gcd
    int x1 = y;
    int y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int main(){
    //cout<<modPow(2, 5)<<endl;
    extendedEuclid(3, 6);
    //x+=19;
    cout<<"X: "<<x<<" Y: "<<y<<" d: "<<d<<endl;
    return 0;
}
