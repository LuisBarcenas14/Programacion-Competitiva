#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX_N 100


struct Arreglo{ double arr[MAX_N][MAX_N]; };

int main(){
    //freopen("in-gauss","r",stdin);
    int n;
    double db;
    cin>>n;
    //AugmentedMatrix Aug1[n][n];
    Arreglo x;
    for(int i=0;i<n;i++){
        for(int j=0;j<n; j++)
            cin>>x.arr[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n; j++)
            cout<<x.arr[i][j]<<" ";
    }

    return 0;
}
