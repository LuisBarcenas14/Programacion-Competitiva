#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int lli;
#define endl '\n'
#define pb push_back
#define MAX 5001
#define mod 1000000000

int A[1001];
int dp[1001][3];
int N;

int contar(int i, int act){
    if(i==N){
        if(act%3==0) return 1;
        return 0;
    }
    //cout<<"I: "<<i<<" act: "<<act<<endl;
    int a= dp[i+1][(act+A[i])%3]!=-1 ? dp[i+1][(act+A[i])%3] : dp[i+1][(act+A[i])%3]=contar(i+1, (act+A[i])%3 );
    //cout<<"a-I: "<<i<<" act: "<<act<<endl;
    a=(a + (dp[i+1][act]!=-1 ? dp[i+1][act] : dp[i+1][act]=contar(i+1, act)) )%mod;
    return a;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    int t,a,b,s1,s2;
    cin>>N;
    for(int i=0;i<1001;i++){
        dp[i][0]=-1;
        dp[i][1]=-1;
        dp[i][2]=-1;
    }
    for(int i=0;i<N;i++){

        cin>>a;
        A[i]=a%3;
    }
    cout<<contar(0, 0)-1<<endl;
}
