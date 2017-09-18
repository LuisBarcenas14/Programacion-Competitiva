#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int main(){
    int n,a,x,e;
    a=12,e=3;
    double b=e*log(a)/log(10);
    n =(int)b;
    x=n-2;
    if(b>2){ b-=x; }
    double r=exp(b*log(10));
    //cout<<r<<endl;
    printf("%03d\n", (int)r);
    int z;
    cin>>z;
    printf("%b\n",z);
    return 0;
}


