#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define endl '\n'
#define pb push_back
#define MAX 46341//31623

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    vector<char> s;
    int t;
    char c;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>c;
        s.pb(c);
    }
    sort(s.begin(), s.end());
    int n = s.size();
    if(n%2==1){
        cout<<s[n/2]<<endl;
    }else
        cout<<s[n/2]<<endl;
    return 0;
}
