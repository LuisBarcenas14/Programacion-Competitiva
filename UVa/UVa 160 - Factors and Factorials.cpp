#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define endl '\n'
#define MAX 101
#define pb push_back

bool criba[MAX];
vi primos;
int i,j,p,f,e;

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.pb(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
}

void pf(int n){
    j=0; p=primos[j];
    i=1;
    while(p<=n && p){
        f=n; e=0;
        while(p<=f){
            f/=p;
            e+=f;
        }
        if(i==0){ i++; printf("\n      "); }
        printf("%3d",e);
        p=primos[++j]; i=(i+1)%16;
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    int n;
    while(cin>>n && n){
        printf("%3d! =",n);
        pf(n);
        printf("\n");
    }
    return 0;
}
