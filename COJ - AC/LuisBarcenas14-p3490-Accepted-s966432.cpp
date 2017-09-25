#include <iostream>

using namespace std;
#define endl '\n'
#define ios ios_base::sync_with_stdio(0); cin.tie(0);

int n,m,d,r;

int main()
{
    ios;
    cin>>n;
    while(n--){
        cin>>m>>d;
        cout<<(d- d/m)<< endl;
    }
    return 0;
}