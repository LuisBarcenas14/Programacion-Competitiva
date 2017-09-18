#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int lli;
#define endl '\n'
#define pb push_back
#define MAX 5001

bool criba[MAX];
int i,j,p,e;
vi primos;

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.pb(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
}

lli sumDiv(int n){
    j=0;p=2;
    lli ans=1;
    while(p*p<=n){
       e=0;
       while(n%p==0){
        n/=p;
        e++;
       }
       ans*= ((lli)pow((double)p, e+1.0)-1)/(p-1);
        p=primos[++j];
    }
    if(n!=1){
        ans*= ((lli)pow((double)n, 2.0)-1)/(n-1);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    int t,a,b,s1,s2;
    cin>>t;
    while(t--){
        cin>>a>>b;
        s1=sumDiv(a);
        s1-=a;
        s2=sumDiv(b);
        s2-=b;
        if(s1==b || s2==a)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
