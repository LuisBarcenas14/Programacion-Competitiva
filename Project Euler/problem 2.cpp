#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int MAX = 4000000;
ll s=0;
int a,b,t;

void res(){
    a=1, b=2;
    while(b<MAX){
        //if(a%2==0) s+=a;
        if(b%2==0) s+=b;
        t=a; a=b; b=b+t;
    }
}

int main(){
    //freopen("in","r",stdin);
    freopen("out","w",stdout);
    res();
    cout<<s<<endl;
}

