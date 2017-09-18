#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int lli;
#define endl '\n'
#define Lim 86029000

vector<bool> criba((Lim>>1)+100);
vi primos;
lli i,j,p,ma,n;

void sieve(){
    for(int i=3;i<=9257;i+=2)
        if(!criba[(i-3)>>1])
            for(int j=i*i;j<Lim;j+=i)
                if(j&1)
                    criba[(j-3)>>1]=1;
    primos.push_back(2);
    for(int i=0;2*i<Lim;i++)
        if(!criba[i])
            primos.push_back(2*i+3);
}

void pf(lli n){
    lli on=n,k=0;
    j=0;
    p=primos[j];
    while(p*p<=n &&p){
        if(n%p==0){
            ma=p;
            k++;
            while(n%p==0){
                n/=p;
            }
        }
        p=primos[++j];
    }
    if(n!=1 && n!=on){
        cout<<n<<endl;
    }else if(n==on || k==1){
        cout<<"-1\n";
    }else{
        cout<<ma<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    sieve();
    while(cin>>n && n){
        if(n<0){ n*=-1; }
        pf(n);
    }
    return 0;
}


