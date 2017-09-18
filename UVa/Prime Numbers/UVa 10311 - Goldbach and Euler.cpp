#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pb push_back
#define endl '\n'
#define MAX 100000001

#define Lim 100000001//86029000

//vector<bool> criba((Lim>>1)+100);
bool criba[MAX];
vector<int> primos;
lli i,j;
/*
void sieve(){
    for(int i=3;i<=2934;i+=2)
        if(!criba[(i-3)>>1])
            for(int j=i*i;j<Lim;j+=i)
                if(j&1)
                    criba[(j-3)>>1]=1;

    primos.pb(2);
    for(int i=0;2*i<Lim;i++){
        if(!criba[i])
            primos.pb(2*i+ 3);
    }
}
*/

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.pb(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
}

/*
void sieve(){
    for(int i=4; i<MAX; i+=2) criba[i]=true;
    for(int i=3;i*i<MAX;i+=2)
        if(!criba[i]) for(int j=i*i; j<MAX; j+=i)
            criba[j]=true;
    primos.pb(2);
    for(int i=3;i<MAX;i+=2)
        if(!criba[i]) primos.pb(i);
}
*/



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    sieve();
    //cout<<criba.size()<<" "<<primos[primos.size()-1]<<endl;
    int n,m,k,p,d,x,p1,p2;
    bool b=false;
    while(cin>>n){
        b=false;
        p1=p2=0;
        if(n%2 && n>3){
            d=n-2;
            //x=(d-3)/2;
            x=d;
            if(!criba[x]){ p1=2; p2=d; }
            b=true;
        }
        m=n>>1;
        k=upper_bound(primos.begin(), primos.end(), m)-primos.begin();
        //if(k>0){ k--; }
        p=primos[k];


        while(p<=n && p && !b){
            d=n-p;
            x=d;
            //x=(d-3)/2;
            if( d==1 || (d%2==0&&d!=2) || criba[x] || d==p){ p=primos[++k]; continue; }
            if(d==2){
                p1=2; p2=p;
                break;
            }else{
                if(!criba[x]){
                    if(d<=p){ p1=d; p2=p; }
                    else{ p1=p; p2=d; }
                    break;
                }
            }
            p=primos[++k];
        }

        if(p>=n || p1==0){
            printf("%d is not the sum of two primes!\n",n);
        }else{
            printf("%d is the sum of %d and %d.\n",n,p1,p2);
        }
    }
    return 0;
}
