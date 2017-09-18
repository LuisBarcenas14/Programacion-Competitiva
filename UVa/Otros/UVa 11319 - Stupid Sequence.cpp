#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl '\n'
#define MAX_N 100
#define lim 7

// adjust this value as needed
struct AugmentedMatrix { long double mat[MAX_N][MAX_N + 1]; };
struct ColumnVector { long double vec[MAX_N]; };

ColumnVector GaussianElimination(int N, AugmentedMatrix Aug) {
    // O(N^3)
    // input: N, Augmented Matrix Aug, output: Column vector X, the answer
    int i, j, k, l; long double t; ColumnVector X;
    for (j = 0; j < N - 1; j++) {
        // the forward elimination phase
        l = j;
        for (i = j + 1; i < N; i++)
        // which row has largest column value
            if (fabs(Aug.mat[i][j]) > fabs(Aug.mat[l][j]))
                l = i;
                // remember this row l
                // swap this pivot row, reason: to minimize floating point error
        for (k = j; k <= N; k++)
            // t is a temporary double variable
            t = Aug.mat[j][k], Aug.mat[j][k] = Aug.mat[l][k], Aug.mat[l][k] = t;
        for (i = j + 1; i < N; i++)
            // the actual forward elimination phase
            for (k = N; k >= j; k--)
                Aug.mat[i][k] -= Aug.mat[j][k] * Aug.mat[i][j] / Aug.mat[j][j];
    }
    for (j = N - 1; j >= 0; j--) {
        // the back substitution phase
        for (t = 0.0, k = j + 1; k < N; k++) t += Aug.mat[j][k] * X.vec[k];
            X.vec[j] = (Aug.mat[j][N] - t) / Aug.mat[j][j];
            // the answer is here
    }
    return X;
}

int n=1500;
AugmentedMatrix Aug1;
ull X[1510][10];

void pre(){
    for(int i=0;i<n;i++){
        if(i<lim){
            Aug1.mat[i][0]=1;
            Aug1.mat[i][1]=(i+1);
            for(int j=2;j<lim;j++)
                Aug1.mat[i][j]=Aug1.mat[i][j-1]*(i+1);
        }
        X[i][0]=1;
        X[i][1]=(i+1);
        for(int j=2;j<lim;j++)
            X[i][j]=X[i][j-1]*(i+1);
    }
    /*for(int j=0;j<lim;j++)
        cout<<X[2][j]<<" ";
    cout<<endl;*/
}

void imp(ColumnVector res){
    cout<<"matriz---"<<endl;
    for(int i=0;i<lim;i++){
        for(int j=0;j<8;j++)
            cout<<Aug1.mat[i][j]<<" ";
        cout<<endl;
    }
    cout<<"fin matriz---"<<endl;

    for(int j=0;j<lim;j++){
       cout<<res.vec[j]<<" ";
    }
    cout<<endl;
}

int main(){
    freopen("in-g","r",stdin);
    freopen("out-g","w",stdout);
    pre();
    int t;
    bool band=false;
    cin>>t;

    for(int k=0;k<t;k++){

        band=false;
        ColumnVector res;
        for(int i=0;i<n;i++){
            cin>>X[i][lim];
            if(i==lim){
                res = GaussianElimination(lim, Aug1);
            }
            if(i<lim){
                //for(int j=0;j<lim;j++)
                //    Aug1.mat[i][j]=X[i][j];
                Aug1.mat[i][lim]=X[i][lim]; //resultado
            }else{
                ull sum=0;
                for(int j=0;j<lim;j++){
                   sum+=X[i][j]*res.vec[j];
                }
                if(sum!=X[i][lim]){ band=true; break; }
            }
        }
        imp(res);
        if(!band){
            //imp();
            cout<<"YES"<<endl;
        }else{
            cout<<"This is a smart sequence!\n";
        }
    }
    return 0;
}

