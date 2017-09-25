#include <iostream>
#include<string>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

string s;
int n,a,b,t;
bool b1, b2;

void divisible6(string s){
    n = s.size();
    b1=b2=false;
    b=0;
    if(s[n-1]=='0'||s[n-1]=='2'||s[n-1]=='4'||s[n-1]=='6'||s[n-1]=='8'){
        b1=true;
    }
    while(n--){
        b+=s[n]-48;
    }
    if(b%3==0){
        b2=true;
    }
    if(b1&&b2){
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
        divisible6(s);
    }
    return 0;
}
