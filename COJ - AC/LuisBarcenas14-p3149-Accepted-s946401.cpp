#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long int lli;
typedef vector<lli> vlli;
#define ios ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define MAX 50010
#define mod 1000000007

lli r,d,i,j,t0,t1,t2,m,p,e,x,y,p0;
vlli primos, f;
bool criba[MAX];
int n,k;

void generarPrimos(){
    for(i=0;i<MAX;i++){criba[i]=true;}
    for(i=2;i<MAX;i++){
        if(criba[i]==true){
            primos.push_back(i);
            for(j=i*i;j<MAX;j+=i)
                criba[j]=false;
        }
    }
}

void factoriales(){
    f.push_back(1);
    for(i=1;i<MAX;i++){
        f.push_back((f[i-1]*i)%mod);
    }
}

void extendedEuclid(int a, int b) {
    if (b == 0) { x = 1; y = 0; d = a; return; }
    // base case
    extendedEuclid(b, a % b);
    // similar as the original gcd
    int x1 = y;
    int y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

lli prim(int n, int p){
    e=0;
    while(n){
        n/=p;
        //cout<<n<<" "<<b<<" "<<e<<endl;
        e=(e+n)%mod;
    }
    return e;
}

lli pot(lli p, lli exp){
    m = p;
    for(i=1;i<exp;i++){
        p = (p*m)%mod;
    }
    return p;
}

lli res(lli d){
    extendedEuclid(p-1,mod);
    x= x>0 ? x : x+mod;
    //cout<<"D: "<<d<<" P: "<<p<<" E: "<<e<<" X: "<<x<<" T0: "<<t0<<endl;
    p0=pot(p,e+1);
    d = ((d*(p0-1)%mod)*x)%mod;
    //cout<<"D: "<<d<<endl;
    d = d>=0 ? d : (d+mod)%mod;
    return d;
}

void divisores(int n){
    d = 1;
    t0 = n;
    j =0;
    p = primos[j];
    //cout<<"p: "<<p<<endl;
    while(p<=n && p){
        e = prim(n,p);
        d = res(d);
        //cout<<"n: "<<n<<" d: "<<d<<" p: "<<p<<" e: "<<e<<" x: "<<x<<endl;
        n = t0;
        p=primos[++j];
    }
    //cout<<"N final: "<<n<<" D: "<<d<<" f[n]: "<<f[n]<<endl;
    d = (d-f[n])%mod;
    d = d>=0 ? d : d+mod;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    generarPrimos();
    factoriales();
    cin>>k;
    while(k--){
        cin>>n;
        divisores(n);
        cout<<d<<endl;
    }
    return 0;
}
