#include <iostream>
#include<string>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

string s;
int n,a,b,t;

void divisible4(string s){
    n = s.size();
    if(n==1){
        if(s[0]=='4'||s[0]=='8'||s[0]=='0'){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }else{
        a = (s[n-2]-48)*10+(s[n-1]-48);
        //cout<<a<<endl;
        if((a&3)==0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}


int main()
{
    ios;
    cin>>t;
    while(t--){
        cin>>s;
        divisible4(s);
    }
    return 0;
}