#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define endl '\n'
#define mod 1000000000

int dp[1001][3];
int N;
int A[1000];

int contar(int i, int acu){
    if(i==N){
        if(acu%3==0) return 1;
        else return 0;
    }

    int a = dp[i+1][(acu+A[i])%3]!=-1 ? dp[i+1][(acu+A[i])%3] :  dp[i+1][(acu+A[i])%3]=contar(i+1, (acu+A[i])%3 );
    a = (a + (dp[i+1][acu]!=-1 ? dp[i+1][acu] : dp[i+1][acu]= contar(i+1, acu)) )%mod;
    return a;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a;
    for(int i=0;i<1001;i++){ dp[i][0]=dp[i][1]=dp[i][2]=-1; }
    cin>>N;
    for(int i=0;i<N;i++){ cin>>a; A[i]=a%3; }
    //cout<<N<<endl;
    cout<<(contar(0, 0)-1)<<endl;;
}
