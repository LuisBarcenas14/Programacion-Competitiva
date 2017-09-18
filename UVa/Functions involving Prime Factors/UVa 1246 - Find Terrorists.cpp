#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define endl '\n'
#define pb push_back
#define MAX 10001//10000

vi primos;
bool criba[MAX];
lli i,j,p,x,sum,e;

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.pb(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
}

lli sumDiv(lli n){
    lli ans=1;
    j=0, p=2;
    criba[0]=criba[1]=true;
    while(p*p<=n){
        e=0;
        while(n%p==0){ n/=p; e++;}
        ans*=(e+1);
        p=primos[++j];
    }
    if(n!=1){ ans*=2; }
    return ans;
}

bool divs[MAX];

void preNumDiv(){
    for(i=2;i<MAX;i++){
        lli temp=sumDiv(i);
        if(!criba[temp])
            divs[i]=true;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    preNumDiv();
    int t,i,j,x;
    lli n;
    cin>>t;
    while(t--){
        cin>>i>>j;
        if(i>j){ x=i; i=j; j=x; }
        bool band=false;
        while(i<=j){
            if(divs[i]){
                if(!band){ cout<<i;}
                else{ cout<<" "<<i;}
                band=true;
            }
            i++;
        }
        if(!band){ cout<<"-1"; }
        cout<<endl;
    }
    return 0;
}
