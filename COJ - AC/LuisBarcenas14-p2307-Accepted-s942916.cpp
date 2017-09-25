#include <iostream>
#include<string>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

//" is the symbol for 1, V for 5, X for 10, L for 50, C for 100, D for 500 and M for 1000";

static const char r1 = 'I',r5 ='V',r10 ='X',r50 ='L',r100 ='C',r500 ='D',r1000 ='M';

int n,l,r,t,b1,b2,x,p;
string cad;

int num(char c){
    switch(c){
        case r1:
            r=1;
        break;
        case r5:
            r=5;
        break;
        case r10:
            r=10;
        break;
        case r50:
            r=50;
        break;
        case r100:
            r=100;
        break;
        case r500:
            r=500;
        break;
        case r1000:
            r=1000;
        break;
    }
    return r;
}

//" is the symbol for 1, V for 5, X for 10, L for 50, C for 100, D for 500 and M for 1000";

int romano2(string s){
    l = s.size();
    t=0;
    l--;
    b1 = num(s[l]);
    while(l){
        t+=b1;
        b2=0;
        l--;
        if(l>=0){
            b2 = num(s[l]);
        }
        if(b1>b2){
            t=t-b2-b2;
        }
        b1=b2;
        //cout<<"Resta: "<<t<<" "<<l<<" "<<b2<<" "<<b1<<endl;
    }
    t+=b1;
    return t;
}

string divisible3(int a){
    x = 2048;
    p=0;
    while(x){
        p+=x&a;
        x>>=1;
    }
    return p%3==0 ? "YES":"NO";
}

int main()
{
    ios;
    cin>>n;
    while(n--){
        cin>>cad;
        t = romano2(cad);
        cout<<divisible3(t)<<" "<<t<<endl;
    }
    return 0;
}