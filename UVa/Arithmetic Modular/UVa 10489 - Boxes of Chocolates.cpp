#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    int t,mod,b,k,a,ans,chocolates,box;
    cin>>t;
    while(t--){
        cin>>mod>>b;
        ans=0;
        while(b--){
            cin>>k;
            k--;
            box=1;
            while(k--){
                cin>>a;
                box=(box*a)%mod;
            }
            cin>>chocolates;
            box=(box*chocolates)%mod;
            //cout<<"boxes: "<<box<<endl;
            ans=(box+ans)%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
