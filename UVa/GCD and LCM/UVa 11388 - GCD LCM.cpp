#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int g,l,t,a,b;
    cin>>t;
    while(t--){
        cin>>g>>l;
        if(l%g!=0){ cout<<"-1"<<endl; continue; }
        //if(l==g){ cout<<l<<" "<<g<<endl; continue; }
        //a=l/g;
        //b=l/a;
        cout<<g<<" "<<l<<endl;
    }
}
