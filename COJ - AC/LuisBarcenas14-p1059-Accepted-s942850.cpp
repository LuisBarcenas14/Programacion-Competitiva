#include <iostream>
#include<stack>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n";

int a,b,p,x;
stack<char> bits;
char c;

int main()
{
    ios;
    while(cin>>a && a){
        p=0;
        while(a){
            if(a&1==1){
                bits.push('1');
                p++;
            }else{
                bits.push('0');
            }
            a>>=1;
        }
        cout<<"The parity of ";
        while(!bits.empty()){
            cout<<bits.top();
            bits.pop();
        }
        cout<<" is "<<p<<" (mod 2)."<<endl;
    }
    return 0;
}