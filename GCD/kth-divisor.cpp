#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
#define endl '\n'

lli a,b,n,i,x;
vector<lli> pf;

lli gcd(lli a, lli b){
    return b==0 ? a:gcd(b, a%b);
}

void res(){
    pf.clear();
    for(i=1;i*i<=a;i++){
        x=a/i;
        if(a%i==0){
            pf.push_back(i);
            if(i!=x)
                pf.push_back(x);
        }

    }
    sort(pf.begin(), pf.end());
    //for(int i=0; i<pf.size(); i++) cout<<pf[i]<<" ";
    //cout<<pf[0]<<endl;
    if(b>pf.size()){
        cout<<"-1"<<endl;
    }else{
        cout<<pf[b-1]<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin>>a>>b){
        res();
    }
    return 0;
}
