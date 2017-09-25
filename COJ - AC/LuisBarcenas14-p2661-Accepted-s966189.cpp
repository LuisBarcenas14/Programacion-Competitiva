#include <iostream>
#include <string>
using namespace std;
#define endl '\n'
#define ios ios_base::sync_with_stdio(0); cin.tie(0);
string s;
int i,t;

int main()
{
    ios;
    while(cin>>s){
        t=0;
        for(i=0;s[i]!='\0';i++){
            t=(t+s[i]-48)%3;
        }
        if(t==1){
            cout<<'7'<<endl;
        }else if (t==2){
            cout<<'4'<<endl;
        }else{
            cout<<'1'<<endl;
        }
    }
    return 0;
}
