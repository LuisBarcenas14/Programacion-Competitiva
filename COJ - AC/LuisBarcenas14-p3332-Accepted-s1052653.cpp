#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define endl '\n'
#define MAX 1000010

bool criba[MAX];
vector<lli> primos;
vector<lli> pf;
lli i,j,n,t,p,a,b,p1,p2,pg,g;

void sieve(){
    for(i=2;i<MAX;i++){
        if(!criba[i]){
            primos.push_back(i);
            for(j=i*i;j<MAX;j+=i)
                criba[j]=true;
        }
    }
}

lli gcd(lli a, lli b){
    return b==0 ? a:gcd(b, a%b);
}

lli lcm(lli a, lli b){
    return a/gcd(a,b)*b;
}

lli numPF(lli n, lli g){
    j=0; p=primos[j];
    lli ans=0,e=0,eg=0;
    while(p*p<=n && j<primos.size()){
        if(n%p==0){
            e=eg=0;
            while(g%p==0){
                g/=p;
                eg++;
            }
            while(n%p==0){
                n/=p;
                e++;
            }
            e-=eg;
            if(e>0) ans++;
        }
        p=primos[++j];
    }
    //cout<<endl;
    if(n!=1 && n!=g) ans++;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    sieve();
    cin>>t;
    while(t--){
        cin>>a>>b;
        //cout<<"gcd: "<<gcd(a,b)<<" lcm: "<<lcm(a,b)<<endl;
        g=gcd(a,b);
        if(a==b){ cout<<"1"<<endl; continue; }
        if(b%a!=0){ cout<<"0"<<endl; continue; }
        //cout<<"p1: ";
        p1=numPF(a,g);
        p2=numPF(b,g);
        p1+=p2;
        //cout<<p1<<" "<<p2<<endl;
        lli q = (lli)pow(2,p1-1);
        cout<<q<<endl;
    }
    return 0;
}
