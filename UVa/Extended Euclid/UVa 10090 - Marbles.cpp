#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

ll x,y,d;

void extendedEuclid(ll a, ll b){
    if(b==0){ d=a; x=1;y=0; return; }
    extendedEuclid(b, a%b);
    ll x1=y;
    ll y1=x-(a/b)*y;
    x=x1;
    y=y1;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    ll a,b;
    ll n,c,c1,c2,n1,n2,cost1,cost2,t,minX, minY,k;
    while(cin>>n && n){
        cin>>c1>>n1>>c2>>n2;
        extendedEuclid(n1,n2);
        if(n%d!=0){
            cout<<"failed"<<endl;
            continue;
        }
        k=n/d;
        x*=k;
        y*=k;
        n1/=d;
        n2/=d;

        //Ajustar X y Y
        if(x<0){
            t=-(x/n2)+(x%n2 != 0);
            x+=t*n2;
            y-=t*n1;
        }
        if(y<0){
            t=-(y/n1)+(y%n1 != 0);
            x-=t*n2;
            y+=t*n1;
        }

        if(x<0 || y<0){
            cout<<"failed"<<endl;
            continue;
        }
        //Minimizar x
        t=(x/n2);
        x-=t*n2;
        y+=t*n1;
        cost1=c1*x+c2*y;
        minX=x;
        minY=y;

        //Minimizar y
        t=(y/n1);
        x+=t*n2;
        y-=t*n1;
        cost2=c1*x+c2*y;
        if(cost2<cost1){ minX=x; minY=y; }

        cout<<minX<<" "<<minY<<endl;
    }
    return 0;
}
