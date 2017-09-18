#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define MAX 1000010

bool criba[MAX];
vector<int> primos;
vector<ii> twin;
lli i,j,p,ans;
lli perfect[31];

void sieve(){
    int k=0;
    criba[1]=true;
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.pb(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }

}

lli pow2(lli n, lli e){
    lli r=1,b=n;
    while(e--){
        r*=b;
    }
    return r;
}

lli sumDiv(lli n){
    j=0; p=primos[j];
    ans=1;
    while(p*p<=n){
        lli power=0;
        while(n%p==0){ n/=p; power++; }
        ans*= (pow2(p, power+1)-1) / (p-1);
        //cout<<"ans1: "<<ans<<endl;
        p=primos[++j];
    }
    //cout<<"n: "<<n<<endl;
    if(n!=1) ans*=(pow2(n, 2)-1) / (n-1);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    sieve();
    //cout<<twin.size()<<endl;
    lli n,r,s;
    while(cin>>n && n){
        if(perfect[n-1]==0){
            r=( (lli) pow((double)2, n-1) * (pow((double)2, n)-1) );
            //cout<<"r: "<<r<<endl;
            s=sumDiv(r);
            //cout<<"s: "<<s<<" "<<2*r<<endl;
            //cout<<s<<endl;
            if(s==2*r){ perfect[n-1]=r; }else{ perfect[n-1]=-1; }
        }
        if(perfect[n-1]>0){
            cout<<"Perfect: "<<perfect[n-1]<<"!\n";
        }else{
            if(!criba[n])
                cout<<"Given number is prime. But, NO perfect number is available.\n";
            else
                cout<<"Given number is NOT prime! NO perfect number is available.\n";
        }

        //printf("(%d, %d)\n",twin[n-1].first, twin[n-1].second);
    }
    return 0;
}
