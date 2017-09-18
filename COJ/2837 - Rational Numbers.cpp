#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define endl '\n'
#define MAX 14151

vector<lli> f;
lli i,j,n,p,c,d,t,t2;
bool criba[2000000];
vi primos;

void gen(){
    f.push_back(0);
    f.push_back(1);
    for(i=2;i<MAX;i++){
        f.push_back(f[i-1]+i);
    }
}

lli gcd(lli a, lli b){
    return b==0 ? a:gcd(b, a%b);
}

void sieve(){
    for(i=2;i<MAX;i++){
        if(!criba[i]){
            primos.push_back(i);
            for(j=i*i;j<MAX;j+=i)
                criba[j]=true;
        }
    }
}

int main(){
    freopen("in","r",stdin);
    gen();
    sieve();
    for(i=0;i<30;i++)  cout<<f[i]<<" ";
    cout<<f[MAX-1]<<" size: "<<primos.size()<<endl;
    while(cin>>n){
        int r=lower_bound(f.begin(), f.end(), n)-f.begin();
        cout<<"r1. "<<r<<endl;
        d=f[r]-n;
        cout<<"n. "<<n<<" r. "<<r<<" d. "<<d<<endl;
        r-=d;
        c=d+1;
        if(r==1){
            if(c==1){ cout<<"0\n"; continue; }
            else{
                c/=2;
                if(c%1)
                    cout<<"-"<<c<<endl;
                else
                    cout<<c<<endl;
            }
        }else{
            cout<<"R: "<<r<<" C: "<<c<<endl;
            p=primos[r-2];
            //p=1;
            for(i=1;c>=0;i++){
                if(gcd(p, i)==1){
                    c-=2; t2=t; t=i;
                }
            }
            if(c==-1)
                cout<<--i<<"/"<<p<<endl;
            else
                cout<<"-"<<t2<<"/"<<p<<endl;
        }
        //cout<<"r: "<<r<<" c: "<<c<<endl;
    }
    return 0;
}
