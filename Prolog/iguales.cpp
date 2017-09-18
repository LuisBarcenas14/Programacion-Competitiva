#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    freopen("in","r",stdin);
    string s1,s2;
    int i=1;
    while(cin>>s1>>s2){
        if(s1==s2)
            cout<<"OK "<<endl;
        else
            cout<<"WA Case: "<<i<<endl;
    }
    return 0;
}
