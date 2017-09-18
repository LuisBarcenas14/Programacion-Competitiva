#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define endl '\n'
#define MAX 10000

lli a,b,s,i,j,m,q,a1;
int r[MAX],t[MAX];

void gen(){
    int n=0,nt=0;
    for(i=0, j=5; i<MAX; i+=2){
        t[i]=r[i]=-1; n++;
        if(j<MAX){ n++; t[j]=r[j]=-1; j+=10; }
    }
    //cout<<"n: "<<n<<endl;
    s=0;
    j=1;
    while(n<MAX){
        //q=(lli)sqrt(s);

        for(i=1; i<=MAX; i++){
            if(t[i]==-1) continue;
            //t[i] = (t[i]+1)%i;
            //a1=(s*10+1)%i;
            t[i]=((t[i]*10)%i+1)%i;
            //t[i]=(a1+t[i])%i;
            if(t[i]==0){
                t[i]=-1; r[i]=j; n++;
            }

        }
        //if(nt==n) break;
        //nt=n;
        j++;
    }
    //cout<<"n: "<<n<<" ";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    gen();
    //cout<<"end"<<endl;
    while(cin>>a){
        cout<<r[a]<<endl;
    }

    return 0;
}
