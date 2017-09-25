#include <iostream>

using namespace std;
typedef long long int lli;
#define endl '\n'
#define ios ios_base::sync_with_stdio(0); cin.tie(0);

lli l,g,t,a,b;
//int gcd(int a, int b){ return b==0 ? a:gcd(b, a%b); }

//int lcm(int a, int b){ g=gcd(a,b); return a*(b/g); }

int main()
{
    ios;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(b%a==0){
            cout<<a<<" "<<b<<endl;
        }else{
            cout<<"-1"<<endl;
        }

    }
    return 0;
}
