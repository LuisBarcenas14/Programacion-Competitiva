#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define endl '\n'
#define MAX 200001

int x1,x2,x3,x4,y,y2,y3,y4;
bool f[501][501];

int w,h,n,i,j,x;

void colorear(int x1, int y1, int x2, int y2){
    for(i=x1;i<=x2;i++){
        for(j=y1;j<=y2;j++)
            f[i][j]=true;
    }
}

int main(){
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    string s;
    while(cin>>w>>h>>n && (w||h||n)){
        for(i=1;i<=w;i++){
            for(j=1;j<=h;j++)
                f[i][j]=false;
        }
        for(int i=0;i<n;i++){
            cin>>x1>>y>>x2>>y2;
            if(x1<=x2){
                x3=x1; x4=x2;
            }else{
                x4=x1; x3=x2;
            }

            if(y<=y2){
                y3=y; y4=y2;
            }else{
                y4=y; y3=y2;
            }

            colorear(x3,y3,x4,y4);

        }
        int k=0;
        for(i=1;i<=w;i++){
            for(j=1;j<=h;j++)
                if(f[i][j]==false)
                    k++;
        }

        if(k==0){
            cout<<"There is no empty spots.\n";
        }else if(k==1){
            cout<<"There is one empty spot.\n";
        }else{
            cout<<"There are "<<k<<" empty spots.\n";
        }
        //cin>>s;
    }
    return 0;
}
