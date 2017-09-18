#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int lli;
#define endl '\n'
#define MAX 1000010

bool criba[MAX];
lli i,j,p;
vi primos;

int gcd(int a, int b){
    return b==0 ? a: gcd(b, a%b);
}

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.push_back(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }

    //for(i=2;i<10;i++){ cout<<primos[i]<<" "; }
    //cout<<endl;
}


void pf(long n, bool pos){
    bool band=false;
    j=0,p=2;
    int e,k=0,et=1,emin=1<<31-1,g;
    long long ans=1;
    vi f;
    while(p<=n &&p){
        if(n%p==0){
            e=0;
            while(n%p==0){
                n/=p;
                e++;
            }
            //if(k>0 && e!=et;){ band=true; break; }else{ f.push_back(p); }
            k++;
            if(k>1){
                g=gcd(e,et);
                //cout<<"g:"<<g<<" ";
                /*if(e>et && g!=1){ et=et; }
                else if(e==et || (et>e && g!=1) ){ et=e; }*/
                if(g!=1){ et=g; }
                else { band=true; break; }
            }else{
                et=e;
            }
             //cout<<p<<"^"<<e<<" ";
        }
        p=primos[++j];

    }
    //cout<<"et:"<<et<<" "<<"n: "<<n<<" ";
    if(n!=1){ band=true; }
    if(!band && pos)
        cout<<et<<endl;
    else if(!band && !pos){
        while(et%2==0){
            //cout<<"et:"<<et<<" ";
            et/=2;
        }
        if(et==0)
            cout<<1<<endl;
        else
            cout<<et<<endl;
    }
    else
        cout<<1<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    sieve();
    long n,d;
    while(cin>>n && n){
        if(n==1){ cout<<"1"<<endl; continue; }
        bool pos=true;
        if(n<0){ n*=-1; pos=false; }
        pf(n, pos);
    }
    return 0;
}

