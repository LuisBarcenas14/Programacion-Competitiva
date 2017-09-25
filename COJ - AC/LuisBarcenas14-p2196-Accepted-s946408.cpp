#include<string>
#include <iostream>
using namespace std;
#define endl "\n"
#define ios ios_base::sync_with_stdio(0);cin.tie(0);

int k,a;
string s;

int main()
{
    ios;
    cin>>k;
    while(k--){
        cin>>s;
        if((s[s.size()-1]-48)%2==0){cout<<"even"<<endl;}else{cout<<"odd"<<endl;}
    }
    return 0;
}