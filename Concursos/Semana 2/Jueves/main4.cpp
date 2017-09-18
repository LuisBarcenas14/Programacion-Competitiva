#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define endl '\n'
#define MAX 100

lli i[101], v[101], x[101], l[101], c[101];
lli si[101], sv[101], sx[101], sl[101], sc[101];
lli t,n,j;

void many(lli n){
    lli nn=n;
    if(n==100){ c[nn]++; n-=100; }
    if(n>=90){ x[nn]++; c[nn]++; n-=90; }
    if(n>=50){ l[nn]++; n-=50; }
    if(n>=40){ x[nn]++; l[nn]++; n-=40; }
    while(n>=10){ x[nn]++; n-=10; }
    if(n==9){ i[nn]++; x[nn]++; n-=9; }
    if(n>=5){ v[nn]++; n-=5; }
    if(n==4){ i[nn]++; v[nn]++; n-=4; }
    while(n>=1){ i[nn]++; n-=1; }
}

void rom(){
    si[1]=1;
    i[1]=1;
    for(j=2;j<=MAX;j++){
        many(j);
        si[j]=si[j-1]+i[j];
        sv[j]=sv[j-1]+v[j];
        sx[j]=sx[j-1]+x[j];
        sl[j]=sl[j-1]+l[j];
        sc[j]=sc[j-1]+c[j];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    rom();
    while(cin>>n && n){
        cout<<n<<": "
        <<si[n]<<" i, "
        <<sv[n]<<" v, "
        <<sx[n]<<" x, "
        <<sl[n]<<" l, "
        <<sc[n]<<" c\n";
    }
    return 0;
}

