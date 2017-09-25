#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int MAX = 31632;

bool divi[MAX];

int main(){
    //freopen("in-po","r",stdin);
    int t;
    cin>>t;
    ll n, i,d,nt,e,ans, dt;
    while(t--){
        cin>>n;
        d=2;
        ans=0;
        memset(divi, 0, sizeof divi);
        while(d*d<=n){
            nt = n;
            e = 0;
            if((nt%d==0)){
                dt = d;
                divi[d] = true;
                while(nt%d==0){
                    nt/=d;
                    if(dt < MAX && !divi[dt]){
                        ans++;
                        divi[dt]=true;
                    }
                    dt*=d;
                }
            }
            ++d;
        }
        cout<<ans<<endl;
    }
}
