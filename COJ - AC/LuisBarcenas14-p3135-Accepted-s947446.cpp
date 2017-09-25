#include <iostream>
using namespace std;
typedef long long int lli;
#define endl "\n"
#define MAX 5001
#define ios ios_base::sync_with_stdio(0);cin.tie(0);
#define mod 1000000000
lli f[MAX];
lli f2[MAX];
lli i,a,t,m,m2,m3,d,mt,dt;

void factorial(){
    f[0]=1;
    f[1]=1;
    f[2]=2;
    f[3]=6;
    f[4]=24;
    f[5]=12;
    f[6]=72;
    f[7]=504;
    for(i=8;i<MAX;i++){
        //m=( f[i-1]*(i) )%100000;
        m=( f[i-1]*(i) )%mod;
        d=mod*10;
        while(m%10==0){
            m/=10;
        }
        f[i] = m;
    }
}

int main()
{
    ios;
    factorial();
    cin>>t;
    while(t--){
        cin>>a;
        mt = f[a]%10;
        cout<<mt<<endl;
    }
    return 0;
}