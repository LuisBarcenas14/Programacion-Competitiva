#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define endl '\n'
#define mod 27
#define base 10

int main(){
    string s;
    char c;
    lli sum=0,CRC;
    while(cin>>CRC){
        CRC = ((mod - ((CRC*base)%mod*base))%mod + mod)%mod;

        cout<<"CRC: "<<CRC<<endl;
    }
    return 0;
}
