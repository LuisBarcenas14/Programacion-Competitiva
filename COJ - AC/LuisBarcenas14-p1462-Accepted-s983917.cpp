#include <bits/stdc++.h>

using namespace std;
#define ios ios_base::sync_with_stdio(0); cin.tie(0);
#define mod 128

string s;
int l,i,j,sum,m,t;

int res(string s){
    l = s.size();
    m=0;
    for(i=0;i<l;i++){
        m = (m*10+(s[i]-'0'))%mod;
    }
    return m;
}

int main()
{
    ios;
    cin>>t;
    while(t--){
        cin>>s;
        sum = (sum+res(s))%mod;
    }
    printf("%d\n",sum);
    return 0;
}
