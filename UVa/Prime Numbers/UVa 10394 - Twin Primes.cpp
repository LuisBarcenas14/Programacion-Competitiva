#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define MAX 20000010

bool criba[MAX];
vector<int> primos;
vector<ii> twin;
lli i,j;

void sieve(){
    int k=0;
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.pb(i);
        if(k>0){
            if(primos[k]-primos[k-1]==2)
                twin.pb(mp(primos[k-1], primos[k]));
        }
        k++;
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
    /*
    for(int i=0;i<10;i++){
        printf("(%d, %d) ",twin[i].first, twin[i].second);
    }
    */
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    sieve();
    //cout<<twin.size()<<endl;
    int n;
    while(cin>>n){
        printf("(%d, %d)\n",twin[n-1].first, twin[n-1].second);
    }
    return 0;
}
