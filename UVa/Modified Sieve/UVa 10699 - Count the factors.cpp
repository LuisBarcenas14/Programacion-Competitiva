#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define endl '\n'
#define pb push_back
#define mk make_pair
#define MAX 1001//1000000
bool criba[MAX];
vii pares;
lli i,j,p,sum,e,r;
vi primos;

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.pb(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
}

lli numDifPF(lli n){
    lli j=0,p=2,ans=0,e;
    while(p*p<=n && p){
        e=0;
        if(n%p==0){
            ans++;
            while(n%p==0){ n/=p; }
        }
        p=primos[++j];
    }
    if(n!=1){ ans++; }
    return ans;
}

int res[1000001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("in","r",stdin);
    sieve();
    int n,k=1;
    while(cin>>n && n){
        cout<<n<<" : ";
        if(res[n]==0)
            res[n]=numDifPF(n);
        cout<<res[n]<<endl;
    }
    return 0;
}

