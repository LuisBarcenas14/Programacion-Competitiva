#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    ll n,b,i,j,k,bi,i2;
    bool band;
    while(cin>>n>>b){
        i2=1;
        bi=0;
        while(i2<=n){
            if(bi==b){ break; }
            if(i2&n)
                bi++;
            else
                bi=0;
            i2<<=1L;
        }
        if(bi==b){
            cout<<n<<endl;
            continue;
        }
        i=1L<<b;
        i--;
        j=i|n;
        bi=0;
        i2=1;

        while(i2&j){
            bi++;
            i2<<=1L;
        }
        i2=1;
        //cout<<j<<" bi: "<<bi<<endl;
        while(bi>b){
            j &= ~i2;
            i2<<=1L;
            bi--;
        }
        cout<<j<<endl;
    }
    return 0;
}
