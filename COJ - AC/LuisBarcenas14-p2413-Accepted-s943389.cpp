#include <iostream>
#include<string>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

string s;
int n,a,b,t;

void divisible5(string s){
    n = s.size();
    if(s[n-1]=='0'||s[n-1]=='5'){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}


int main()
{
    ios;
    cin>>t;
    while(t--){
        cin>>s;
        divisible5(s);
    }
    return 0;
}