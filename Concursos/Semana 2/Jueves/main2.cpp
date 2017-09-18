
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define endl '\n'
#define MAX 54

lli f[MAX];
lli n,i,u,t,v,s;
double a,b,c,d,e;

void fib(){
    f[0]=1;
    f[1]=2;
    for(i=2;i<MAX;i++){
        f[i]=f[i-1]+f[i-2];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    fib();
    int k=1;
    while(cin>>n>>a>>b>>c && a){
        switch(n){
            case 1:
                d=(a+b)/2*c;
                e=(b-a)/c;
                printf("Case %d %.3f %.3f\n",k,d,e);
            break;
            case 2:
                e=(b-a)/c;
                d=((b+a)/2)*e;
                printf("Case %d %.3f %.3f\n",k,d,e);
            break;
            case 3:
                d=sqrt(2*b*c+a*a);
                e=(d-a)/b;
                printf("Case %d %.3f %.3f\n",k,d,e);
            break;
            case 4:
                d=sqrt(a*a-2*b*c);
                e=(a-d)/b;
                printf("Case %d %.3f %.3f\n",k,d,e);
            break;
        }
        k++;
    }
    return 0;
}

