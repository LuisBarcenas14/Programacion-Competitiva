#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    int a,b,c,sum;
    string s;
    while(cin>>s){
        a=s[0]-'0';
        b=s[1]-'0';
        c=s[2]-'0';
        sum=3*a+2*b+c;
        cout<<sum<<endl;
    }
    return 0;
}
