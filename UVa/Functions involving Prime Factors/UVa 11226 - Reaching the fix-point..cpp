#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define pb push_back
#define endl '\n'
#define MAX 708

vi primos;
bool criba[MAX];
lli i,j,p,sum,e,k,jt;

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.pb(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
}

lli sumPF(lli n){
    lli ans=0;
    j=0,p=2;
    while(p*p<=n && p){
        while(n%p==0){
            n/=p;
            ans+=p;
        }
        p=primos[++j];
    }
    if(n!=1) ans+=n;
    return ans;
}

lli res[500001];

void preCal(){
    lli li,lj;
    for(li=2;li<=500000;li++){
        sum=sumPF(li);
        lj=li;
        k=1;
        //if(i==8)cout<<sumPF(8)<<endl;
        while(sum!=lj){
            //if(li<=8 && lj>1)cout<<"i: "<<i<<" j: "<<j<<" - sum: "<<sum<<endl;
            //if(li==8){ cout<<"lj: "<<lj<<" sum: "<<sum<<endl; }
            lj=sum;
            //if(i<=8 && j>1)cout<<"i: "<<i<<" j: "<<j<<" - sum: "<<sum<<endl;
            //jt=j;
            sum=sumPF(lj);

            //if(i<=8)cout<<"i: "<<i<<" j: "<<j<<" - sum: "<<sum<<endl;

            k++;
        }
        res[li]=k;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    sieve();
    preCal();
    //cout<<sumPF(8)<<endl;
    int a,b,t,x;
    lli maxi=0;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>a>>b;
        if(a>b){ x=a; a=b; b=x; }
        maxi=0;
        while(a<=b){
            if(res[a]>maxi){ maxi=res[a]; }
            a++;
        }
        cout<<"Case #"<<i<<":\n"<<maxi<<endl;
    }
    return 0;
}

