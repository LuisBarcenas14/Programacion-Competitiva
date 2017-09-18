#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define endl '\n'
#define MAX 1000010
#define pb push_back

bool criba[MAX];
vi primos;
lli i,j,p,f,e;

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.pb(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
}

void pf(int n){
    j=0; p=primos[j];
    i=1;
    bool b=false;
    int fac[10];
    memset(fac, 0, sizeof(fac));
    while(p<=n && p){
        if(n%p==0){
            if(p>10){ b=true; break; }
            e=0;
            while(n%p==0){
                n/=p;
                e++;
            }
            fac[p]+=e;
        }

        p=primos[++j];
    }
    if(n!=1){ b=true; }
    if(b){ cout<<"-1"<<endl; return; }
    vi x;
    /*
    while(fac[2]>0 && fac[3]>0){
        x.pb(6);
        fac[2]--;
        fac[3]--;
    }
    */
    for(i=2;i<=7;i++){
        while(fac[i]>0){
            int num=1;
            while( (i==2||i==3) && num*i<10 && fac[i]>0){
                num*=i;
                fac[i]--;
            }
            if(i>3){ num=i; fac[i]--; }
            x.pb(num);

        }
    }
    sort(x.begin(), x.end());
    b=false;

    int a;
    for(i=0; i<x.size();i++){
        if(x[i]==3 ){
            if(x[0]%2==0 && x[0]<8){ a=0; }else if(x[1]%2==0 && x[1]<8){ a=1; }else{ break; }
            x[i]=6;
            if(x[a]>2){ x[a]>>=1;  }else{ x[a]=1; b=true; }
        }
    }
    sort(x.begin(), x.end());

    i=0;
    if(b){ i++; }
    //if(x[1]==3 && x[0]==2){ x[1]=6; i++; }
    for(;i<x.size();i++){
        cout<<x[i];
    }

    cout<<endl;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    sieve();
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        if(n<10){ cout<<n<<endl; continue; }
        pf(n);
    }
    return 0;
}

