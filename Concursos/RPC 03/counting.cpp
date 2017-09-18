#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define endl '\n'
#define MAX 71
#define LIM 48
#define mod 1000000007

int sum[5001];
ll edges[5001][51];
ll graphs[5001][51];
ll f[5000];

bool criba[MAX];
ll i,j;
vi primos;
ll d,x,y;

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.push_back(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
}

int numDiv(ll n){
    int j=0,p=primos[j],ans=1;
    while(p*p<=n && p){
        if(n%p==0){
            ll e=0;
            while(n%p==0){ n/=p; e++; }
            ans*=(e+1);
        }
        p=primos[++j];
    }
    if(n!=1){ ans*=2; }
    return ans;
}

void pre(){
    int d;
    sum[1]=0;
    f[0]=f[1]=1;
    for(int i=2;i<=5000;i++){
        f[i]=(f[i-1]*i)%mod;
        d=numDiv(i);
        --d;
        sum[i]=d;
        for(int k=1; k<=LIM; k++){
            edges[0][k]=0; edges[i][k]=-1;

            graphs[1][k]=1; graphs[i][k]=-1;
        }//*/
    }
}

void extendedEuclid(ll a, ll b){
    if(b==0){ d=a; x=1; y=0; return; }
    extendedEuclid(b, a%b);
    ll x1=y;
    ll y1=x-(a/b)*y;
    x=x1;
    y=y1;
}

int comb(int n, int r){
    ll down,res;
    down = ((f[r]*f[n-r])%mod+mod)%mod;
    extendedEuclid(down, mod);
    //x= x>=0 ? x : (x+mod);
    x=(x+mod)%mod;
    res = ((f[n]*x)+mod)%mod;
    return res;
}

ll calcR1(int n, int k){
    if(edges[n][k]!=-1){ return edges[n][k]; }
    ll t = (sum[n]>k ? k : sum[n]);
    return edges[n][k]= (  t + calcR1(n-1, k) )%mod;
}

ll calcR2(int n, int k){
    if(graphs[n][k]!=-1){ return graphs[n][k]; }
    ll t = (sum[n]<=k ? 1 : comb(sum[n],k));
    return graphs[n][k]= (  t * calcR2(n-1, k) )%mod;
}

void res(int n, int k){
    ll r1=calcR1(n, k), r2=calcR2(n, k);
    cout<<r1<<" "<<r2<<endl;
}

//MAXI DIVSS IN 5000 IS 48
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out2","w",stdout);
    sieve();
    pre();
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        if(k>LIM){ k=LIM; }
        res(n,k);
    }
    return 0;
}
