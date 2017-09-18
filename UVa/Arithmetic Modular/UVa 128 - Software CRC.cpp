#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define endl '\n'
#define mod  34943

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    char c;
    lli m,r;
    while(getline(cin,s)){
        if(s=="#"){ break; }
        m=0;
        for(int i=0;i<s.size();i++){
            m = ( ((m<<8)%mod)+s[i] )%mod;
        }
        m<<=16;
        r=(mod-m)%mod;
        if(r<0)
            r=(r+mod)%mod;
        printf("%02X %02X\n",r>>8, r%256);
    }
    return 0;
}
