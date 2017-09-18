#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define endl '\n'
#define MAX 1010

bool criba[MAX];
vi primos;

lli i,j,n,c,t,m,p,k,ci,z;

int gcd(int a, int b){
    return b==0? a:gcd(b,a%b);
}

void sieve(){
    primos.push_back(1);
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.push_back(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    sieve();
    z=0;
    while(cin>>n>>c){
        //cout<<"gcd: "<<gcd(n,c)<<" lcm: "<<c/gcd(n,c)*n<<endl;
        cout<<n<<" "<<c<<":";
        j=lower_bound(primos.begin(), primos.end(),n)-primos.begin();
        if(primos[j]>n) j--;

        j++;
        m=j/2;
        //cout<<primos[j]<<" j: "<<j<<" m: "<<m<<endl;
        if(j%2==0)//ar
            i=m-c,c<<=1;
        else
            i=m-(c-1),c=(c<<1)-1;
        //cout<<"c: "<<c<<endl;
        if(i<0) i=0;

        for(k=0; k<c && primos[i]<=n; k++,i++)
            cout<<" "<<primos[i];
        cout<<endl<<endl;
    }
    return 0;
}
