#include <iostream>

using namespace std;
#define MAX 10000000
#define endl '\n'
#define ios ios_base::sync_with_stdio(0); cin.tie(0);
int t,a,b,g,r;

int gcd(int a, int b){ return b==0 ? a : gcd (b, a%b); }

int main()
{
    ios;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a==b){
            cout<<"4"<<endl;
        }else{
            g = gcd(a,b);
            if(g==1){
                r = (a-1)*2+(b-1)*2+4;
                cout<<r<<endl;
            }else{
                r = (a/g-1)*2 + (b/g-1)*2 + 4;
                cout<<r<<endl;
            }
        }
    }
    return 0;
}
