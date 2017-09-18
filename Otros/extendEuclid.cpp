#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


int x,y,d;

void extendEuclid(int a, int b){
    if(b==0){ x=1; y=0; d=a; return; }
    extendEuclid(b, a%b);
    int x1=y;
    int y1=x-(a/b)*y;
    x=x1;
    y=y1;
}

int main(){
    int a,b;
    while(cin>>a>>b){
        extendEuclid(a,b);
        cout<<x<<endl;
    }
}
