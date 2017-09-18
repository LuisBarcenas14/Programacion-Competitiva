#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


double x(int c){
    //if(c!=0){ c++; }else{ c--; }
    c++;
    double x = (-2+sqrt(4-4*c) )/2;
    return x;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b,oa,i,t;
    double sa,sb;
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>a>>b;
        cout<<"Case "<<i<<": ";
        if(a%2==0){ a++; }
        if(b%2==0){ b--; }
        oa=a;
        a=(a-1)/2;
        b=(b-1)/2;
        sa=a*a+2*a+1;
        sb=b*b+2*b+1;
        //cout<<"a: "<<a<<" "<<sa<<" b: "<<b<<" "<<sb<<endl;
        cout<<sb-sa+oa<<endl;
    }
    return 0;
}
