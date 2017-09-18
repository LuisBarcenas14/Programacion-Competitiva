#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 32778

int f[15][MAX];
int ma[15];
//int c[100][15];
int i,j,m,maT,t,n,b,k,x,a;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    cin>>t;
    while(t--){
        cin>>b>>n;
        for(i=0;i<b;i++){
            ma[i]=0;
            for(j=0;j<MAX;j++)
                f[i][j]=0;
        }

        for(i=0;i<n;i++){
            k=1<<(b-1);
            x=0;
            for(j=0;j<b;j++){
                cin>>a;
                if(a){ x+=k; }
                //else{ }
                k>>=1;
                f[j][x]++;
                //cout<<"X: "<<x;
                //printf("%2d- %3d ",j,x);
                if(f[j][x]>ma[j]) ma[j]=f[j][x];
                //if(j==3 && ma[j]==2) cout<<x<<endl;
                //cout<<" ma: "<<ma[j]<<endl;
            }
        }
        for(j=0;j<b;j++){
            //cout<<j<<": "<<ma[j]<<endl;
            if(ma[j]==1){
                cout<<(j+1)<<endl;
                break;
            }
        }
    }
    return 0;
}

/*
0 1 1 1 	0 0
1 0 0 0 	0 0
1 0 1 0 	0 0
1 1 0 0 	0 0
1 1 0 1 	0 0
1 0 0 1 	0 0
1 1 1 0 	0 0
1 1 1 1 	0 0
1 0 1 1 	0 0
0 1 1 0 	0 0
*/
