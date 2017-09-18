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
    double l, c, r,maxi=0;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>l>>c;
        r=(l * 0.7 + c * 0.3);
        if(r>maxi) maxi=r;
    }
    printf("%.2f\n",maxi);
    return 0;
}
