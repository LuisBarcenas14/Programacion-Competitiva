#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int lli;
#define pb push_back
#define endl '\n'
#define MAX 1000001//#define MAX 1000000000001

set<lli> oddSum;
lli i,j,x;
double d;
vector<lli> res;

lli pow2(int n){
    lli r=1;
    while(n--){
        r*=2;
    }
    return r;
}

void pows(){
    for(i=1;i<MAX;i++){
        //if(i<=2) cout<<"i: "<<i<<endl;
        for(j=0;j<=39;j++){
            d=j*log10(2)+2*log10(double (i));
            if(d<=12.0)
                oddSum.insert(pow2(j)*(i*i));

            //if(i<=2 && j<11){ cout<<(pow2(j)*(i*i))<<" "; }
        }
    }
    //cout<<oddSum.size()<<endl;
    for(set<lli>::iterator it=oddSum.begin(); it!=oddSum.end(); it++){
        res.push_back(*it);
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    pows();
    lli n;
    while(cin>>n && n){
        int k=lower_bound(res.begin(), res.end(), n)-res.begin();
        if(res[k]>n || !res[k]){ k--; }
        cout<<(n-(k+1))<<endl;
    }
    return 0;
}
