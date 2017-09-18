#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 2147483647
typedef long long int lli;
typedef vector<int> vi;

lli i,j,n,t,c;

void sieve(int L,int U) {
    int i,j,d;
    d=U-L+1;

    bool *flag=new bool[d];
    for (i=0;i<d;i++) flag[i]=true; /* default: mark all to be true */

    for (i=(L%2!=0);i<d;i+=2) flag[i]=false;

    for (i=3;i<=sqrt(U);i+=2) {
        if (i>L && !flag[i-L]) continue;
        /* choose the first number to be sieved -- >=L,
        divisible by i, and not i itself! */
        j=L/i*i; if (j<L) j+=i;
        if (j==i) j+=i;

        j-=L;
        for (;j<d;j+=i) flag[j]=false;
    }

    if (L<=1) flag[1-L]=false;
    if (L<=2) flag[2-L]=true;

    int ma=-1, mi=MAX, cmi1=0, cmi2=0, cma1=0, cma2=0, k=0,p,dif;
    for (i=0;i<d;i++){
        if (flag[i]){
            if(k){
                dif=i-p;
                if(dif>ma) ma=dif, cma1=p, cma2=i;
                if(dif<mi) mi=dif, cmi1=p, cmi2=i;
            }
            p=i;
            k++;
        }
    }
    if(k>1)
        printf("%d,%d are closest, %d,%d are most distant.\n",cmi1+L,cmi2+L,cma1+L,cma2+L);
    else
        printf("There are no adjacent primes.\n");
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    //cout<<dif.size();
    int a,b;
    while(cin>>a>>b){
        if(a==b){ printf("There are no adjacent primes.\n"); continue; }
        sieve(a,b);
    }
    return 0;
}
