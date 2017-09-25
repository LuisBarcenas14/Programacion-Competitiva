#include <iostream>
#include <string>
using namespace std;
#define endl "\n"
#define ios ios_base::sync_with_stdio(0); cin.tie(0);

int t,n,sum,i,q;
string s;


void esDivisible(string s){
    q=0;
    n = s.size();
    for(i=0;i<n;i++){
        //cout<<"I: "<<i<<" Q: "<<q<<endl;
        switch (q){
            case 0:
                if(s[i]=='1'){ q=1; }
            break;
            case 1:
                if(s[i]=='1'){ q=0; }
                if(s[i]=='0'){ q=2; }
            break;
            case 2:
                if(s[i]=='0'){ q=1; }
            break;
        }
    }
    if(q==0){ cout<<"YES"<<endl; }else{ cout<<"NO"<<endl; }
}

int main()
{
    ios;
    cin>>t;
    while(t--){
        cin>>s;
        esDivisible(s);
    }
    return 0;
}
