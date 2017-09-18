#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define MAX 1000010
#define mod 1000000007

double x[11];
double y[11];

int mod2Inv=500000004;

double dist(double x1, double y1, double x2, double y2){
    return sqrt( (x2-x1)*(x2-x1) +  (y2-y1)*(y2-y1) );
}

ll res(int n, int d){
    ll ans = n*(n-1)/2;
    if(ans==1) return 1;
    return ans*(ans-1)/2;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("A.in","r",stdin);
    int n;
    double d,r;
    while(cin>>n>>d && n){
        bool band=true;
        for(int i=0; i<n; i++)
            cin>>x[i]>>y[i];
        for(int i=0; i<n && band; i++){
            for(int j=i+1; j<n && band; j++){
                r=dist(x[i], y[i], x[j], y[j]);
                if(r>d) band=false;
            }
        }
        //cout<<"band: "<<band<<endl;
        if(!band)
            cout<<"0"<<endl;
        else
            cout<<res(n, d)<<endl;
    }
    return 0;
}



