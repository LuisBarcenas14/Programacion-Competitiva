#include <iostream>
using namespace std;
#define endl '\n'
#define ios ios_base::sync_with_stdio(0); cin.tie(0);

int x,y,d,a,b,c,r,ct,t;

void extendedEuclid(int a, int b){
    if(b==0){ x=1; y=0; d=a;return; }
    extendedEuclid(b, a%b);
    int x1=y;
    int y1=x-(a/b)*y;
    x=x1;
    y=y1;
}

int main()
{
    //ios;
    while(cin>>a>>b>>c && (a||b||c)){
        extendedEuclid(a,b);
        t = c/d;
        //cout<<"X: "<<x<<" Y: "<<y<<endl;
        //ct = a*x+b*y;
        r = t*(a*x+b*y);
        //cout<<"d: "<<d<<" r: "<<r<<endl;
        //cout<<"X: "<<t*x<<" Y: "<<t*y<<endl;
        if(c==r){ cout<<"YES"<<endl; }else{ cout<<"NO"<<endl; }
    }
    return 0;
}
