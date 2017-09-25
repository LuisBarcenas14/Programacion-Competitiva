#include <iostream>
using namespace std;
typedef long long int lli;
#define MAX 1000001
#define mod 1000000007
#define endl "\n"
#define ios ios_base::sync_with_stdio(0); cin.tie(0);

lli f[MAX];
lli i;
int t, a;

void generarValores(){
    f[0] = 1;
    f[1] = 2;
    for(i=2;i<MAX;i++){
        f[i] = (f[i-2] + f[i-1])%mod;
    }
}

int main()
{
    ios;
    generarValores();
    cin>>t;
    while(t--){
        cin>>a;
        cout<<f[a]<<endl;
    }
    return 0;
}
