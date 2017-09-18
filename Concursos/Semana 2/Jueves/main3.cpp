
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define endl '\n'
#define MAX 54

int a,b,t,n;

int gcd(int a,int b){
    return b==0 ? a : gcd(b, a%b);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("in","r",stdin);
    //freopen("out","w",stdout);
    string s1,s2;
    //bitset<31> b1,b2;
    int k=1;
    cin>>t;
    while(t--){
        cin>>s1>>s2;
        bitset<31> b1 (s1);
        bitset<31> b2 (s2);
        if(gcd(b1.to_ulong(),b2.to_ulong())!=1)
            printf("Pair #%d: All you need is love!\n",k);
        else
            printf("Pair #%d: Love is not all you need!\n",k);
        k++;
    }
    return 0;
}


