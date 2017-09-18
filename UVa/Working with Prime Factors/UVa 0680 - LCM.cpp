#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef vector<int> vi;
typedef vector<lli> vlli;
#define endl '\n'
#define MAX 1000001
#define pb push_back

bool criba[MAX];
vi primos;
lli i,j,p,sum;
vector<vlli> pfs;
//int pfs[78500];

int powMod10(lli n, int e){
    lli r=1;
    while(e--){
        r = (r*n)%10;
    }
    return r;
}

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.pb(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
    vlli v;
    for(i=0; i<primos.size();i++){
        p=primos[i];
        sum=p;
        pfs.pb(v);
        while(sum<MAX){
            pfs[i].pb(sum);
            sum*=p;
        }
        pfs[i].pb(sum);
    }
    //for(int i=0;i<10;i++){ cout<<pfs[0][i]<<" "; }
    //cout<<endl;
    //cout<<primos[primos.size()-1]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    sieve();
    int n,e,k,mini;
    //cin>>a;
    //cout<<primos[ lower_bound(primos.begin(), primos.end(), a)-primos.begin() ];
    while(cin>>n && n){
        if(n==1){ cout<<"1"<<endl; continue; }
        //cout<<powMod10(n, e)<<endl;
        sum=1;
        mini=1<<31-1;
        for(i=0; primos[i] && primos[i]<=n; i++){
            k=lower_bound(pfs[i].begin(), pfs[i].end(), n)-pfs[i].begin();
            if(pfs[i][k]>n || pfs[i][k]==0){ k--; }
            if(i==0 || i==2){ //Si p es igual o 2 o 5, eliminar los 0s.
                if(i==2){
                    //cout<<"5^"<<k+1<<" ";
                    if(k+1>=mini){
                        sum = (sum * powMod10(5, k+1-mini))%10;
                    }else{
                        //cout<<powMod10(2, mini-(k+1))<<"- ";
                        sum = (sum * powMod10(2, mini-(k+1) ))%10;
                    }
                }
                if(i==0){ mini=k+1; }
            }else{
                //cout<<primos[i]<<"-"<<k<<" "<<pfs[i][k]<<" : "<<powMod10(primos[i], k)<<endl;
                sum = (sum * powMod10(primos[i], k+1))%10;
            }
            //cout<<primos[i]<<"^"<<k+1<<" ";
        }
        if(i<=2){ sum = (sum * powMod10(2, mini))%10; }
        cout<<sum<<endl;
    }
    return 0;
}

