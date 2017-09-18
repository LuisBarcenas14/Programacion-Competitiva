#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define endl '\n'
#define MAX 1000010
#define delta 1e-4

bool criba[MAX];
long i,j,p,e,mini,e2,dif,a,b;
long d;
vi primos;
double l;

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.pb(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
}

long zeroes(long n, long n2){
    long tn;
    l=0.0;
    j=0;p=2;
    mini=1<<31-1;
    bool b1, b2;

    while(p<=n && p){
        tn=n;
        e=e2=b1=b2=0;
        while(p<=tn){
            tn/=p;
            e+=tn;
        }
        //l+=double(e)*log(double(p));
        if(n2%p==0){
            b2=true;
            while(n2%p==0){
                n2/=p;
                e2++;
            }
        }
        if(b2){
            dif=e/e2;
            if(dif<mini){ mini=dif; }
            if(mini==0) break;
        }

        p=primos[++j];
    }
    if(n2!=1){
        if(n%n2==0){ mini=1; }
        else{ mini=0; }
    }
    if(n!=1){ l+=log(n); }
    if(mini==1<<31-1){ mini=0; }
    return mini;
}

long digits(long a, long b){
    double base=log(double (b)), sum=0.0;
    for(int i=2;i<=a;i++) sum+=log(i);
    d= long((sum/base+delta)+1);
    return d;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    sieve();
    while(cin>>a>>b){
        if(a==0||a==1){ cout<<"0 1\n"; continue; }
        cout<<zeroes(a, b)<<" "<<digits(a,b)<<endl;
    }
    return 0;
}
