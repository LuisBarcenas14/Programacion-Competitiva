#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int MAX=1000010;

int gcd(int a, int b){
    return b==0 ? a: gcd(b, a%b);
}

void res(int n){
    int total=0,limit,notUsed=0,x,y,z;
    bool use[n];
    for(int i=0; i<=n; i++){ use[i]=false; }
    limit=(int) floor(sqrt(n));
    for(int i=1,j=2; i<limit; ){
        if( (z=(j*j+i*i)) <=n && __gcd(i, j)==1){
            //cout<<"i: "<<i<<" j: "<<j<<" z: "<<z<<endl;
            x=2*i*j;
            y=j*j-i*i;
            int k=1;
            total++;
            cout<<"X: "<<x<<" Y: "<<y<<" Z: "<<z<<endl;
            while(z*k<=n){
                //cout<<"k: "<<k<<endl;
                use[x*k]=true;
                use[y*k]=true;
                use[z*k]=true;
                k++;
            }
        }
        j+=2;
        if(j>limit){ ++i, j=i+1; }
    }
    for(int i=1;i<=n;i++){
        if(!use[i])
            notUsed++;
    }
    cout<<total<<" "<<notUsed<<endl;
}


int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int n;
    while(cin>>n){
        res(n);
    }
    return 0;
}
