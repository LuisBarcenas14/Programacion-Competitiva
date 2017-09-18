#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int lli;
typedef pair<int, int> ii;
#define endl '\n'
#define MAX 10
#define MAXP 5000010

bool criba[MAXP];
bool puede[MAXP];
vi primos;
lli i,j;

void sieve(){
    for(i=2;i<MAXP;i++) if(!criba[i]){
        //primos.push_back(i);
        for(j=i*i;j<MAXP; j+=i)
            criba[j]=true;
    }
}

ii par0(int i, int k, int l){
    int dif=i-(k+l);
    l+=dif;
    for(;k>=2 && l<i-1;k--,l++){
        if(!criba[k] && !criba[l]){
            return make_pair(k,l);
        }
    }
    puede[i]=true;
    return make_pair(0,0);
}

void par(int n, int i, int j){
    for(;i>=2 && j<n-1;i--,j++){
        if(!puede[i] && !puede[j]){//!criba[i] && !criba[j]
            ii p1 = par0(i, i/2, i/2);
            ii p2 = par0(j, j/2, j/2);
            if(p1.first!=0 && p1.second!=0
               && p2.first!=0 && p2.second!=0
            ){
                printf("%d %d %d %d\n",p1.first, p1.second, p2.first, p2.second);
                return;
            }
        }
    }
    printf("Impossible.\n");
}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    sieve();
    int n;
    while(cin>>n){
        if(n%2==0)
            par(n, n/2, n/2);
        else
            par(n, n/2, n/2+1);
    }

    return 0;
}

