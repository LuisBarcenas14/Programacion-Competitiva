#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define endl '\n'
#define MAX 100010

#define R 1000
#define C 1000

int cost[R][C];

int min(int x, int y, int z);

int minCost(int cost[R][C], int m, int n)
{
     int i, j;

     int tc[R][C];

     tc[0][0] = cost[0][0];

     for (i = 1; i <= m; i++)
        tc[i][0] = tc[i-1][0] + cost[i][0];

     for (j = 1; j <= n; j++)
        tc[0][j] = tc[0][j-1] + cost[0][j];

     for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            tc[i][j] = min(tc[i-1][j],
                           tc[i][j-1]) + cost[i][j];

     return tc[m][n];
}

int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);
   freopen("in","r",stdin);
   freopen("out","w",stdout);
   int i=0,j=0,r=0,c=0,t;
   cin>>t;
   //cout<<"t: "<<t<<endl;
   while(t--){
        for(i=0;i<R;i++){
            for(j=0;j<C;j++)
                cost[i][j]=0;
        }
        cin>>r>>c;
        for(i=0;i<r;i++){
            for(j=0;j<c;j++)
                cin>>cost[i][j];
        }
        /*
        for(i=0;i<r;i++){
            for(j=0;j<c;j++)
                cout<<cost[i][j]<<" ";
            cout<<endl;
        }
        */
        cout<<minCost(cost, r-1, c-1)<<endl;
   }


   return 0;
}
