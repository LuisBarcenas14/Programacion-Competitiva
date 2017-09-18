#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b,g,t,res;
    cin>>t;
    for(int i=1; i<=t; i++){
        cin>>a>>b;
        cout<<"Case "<<i<<": ";
        g = __gcd(a, b);
        a/=g;
        b/=g;
        if(a>b){ swap(a, b); }
        res=a-b+2*b;
        cout<<res<<endl;
    }
    return 0;
}

