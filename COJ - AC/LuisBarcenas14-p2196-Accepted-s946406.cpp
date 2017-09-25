#include<string>
#include <iostream>
using namespace std;
#define endl "\n"
#define ios ios_base::sync_with_stdio(0);cin.tie(0);

int k,a;
long long int t;
string s;

void esPar(string s){
    a = s[s.size()-1]-48;
    if(a%2==0){cout<<"even"<<endl;}else{cout<<"odd"<<endl;}
}

int main()
{
    ios;
    cin>>k;
    while(k--){
        cin>>s;
        esPar(s);
    }
    return 0;
}