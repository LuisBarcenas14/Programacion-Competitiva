#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define endl '\n'

int main(){
    lli a,b,c,i,m,t;

    string s;
    while(getline(cin, s)&&s!="#"){
        if(s==""){
            cout<<"linea en blanco'\n";
        }else{
            cout<<"algo\n";
        }
    }
    while(cin>>a>>b>>c){
        m=i=1;
        t=a%c;
        while(i<=b){
            if(i&b){
                m=(m*t)%c;
            }
            t=(t*t)%c;
            i<<=1;
        }
        cout<<m<<endl;
    }
    return 0;
}
