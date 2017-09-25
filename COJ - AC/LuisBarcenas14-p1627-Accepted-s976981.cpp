#include <iostream>

using namespace std;
#define ios ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
int t,n,s;
int main()
{
    ios;
    cin>>t;
    while(t--){
        s=0;
        cin>>n;
        while(n>=5){
            n/=5;
            s+=n;
        }
        cout<<s<<endl;
    }
    return 0;
}