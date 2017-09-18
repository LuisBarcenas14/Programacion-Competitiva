#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

ll x, y, d;

void extendedEuclid(ll a, ll b){
    if(b==0){ d=a; x=1; y=0; return; }
    extendedEuclid(b, a%b);
    ll x1=y;
    ll y1=x-(a/b)*y;
    x=x1;
    y=y1;
}

//9x+y
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    ll n,k,a=9,b=1,t,N,M;
    extendedEuclid(a, b);
    x+=b; y-=a;
    ll ox=x, oy=y;
    while(cin>>n && n){
        set<ll> res;
        x=ox, y=oy;
        k=n/d;
        x*=k, y*=k;
        //cout<<"9 ("<<x<<") + ("<<y<<") = "<<n<<endl;
        t=(y/a);
        x+=t*b;
        y-=t*a;
        x-=b;
        y+=a;
        if(y>=0 && y<10)
            cout<<x<<y;
        x+=b;
        y-=a;
        if(y>=0 && y<10)
            cout<<" "<<x<<y;
        cout<<endl;

    }
    return 0;
}

/*
a=1 b=-1
1x-1y=18


x=20 y=2
x=19 y=1

x=10a+b
y=a

a1
a2
------
17

18 1

9(1)+1

M
a=1

-----
18
N=10a+b |10a=10 b=9
M=a | a=1

N-M=18
9(a)+b
9(1)+1(9)=18
9(2)+1(0)=18


*/
