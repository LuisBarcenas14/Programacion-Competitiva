#include <iostream>
using namespace std;
typedef long long int lli;
#define MAX 1001
#define mod 1000007
#define endl "\n"
#define ios ios_base::sync_with_stdio(0);cin.tie(0);

lli dos[MAX];
lli d;
lli i;
int a,b;

void pot2(){
    dos[0] = 1;
    for(i=1;i<MAX;i++){;
        dos[i] = (dos[i-1]<<1)%mod;
    }
}

lli consulta(int a, int b){
    d = 0;
    for(i=a;i<=b;i++){
        d = (d+dos[i])%mod;
    }
}

int main()
{
    ios;
    pot2();
    while(cin>>a>>b && a!=-1){
        consulta(a,b);
        cout<<d<<endl;
    }
    return 0;
}
