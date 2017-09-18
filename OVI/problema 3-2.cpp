#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define endl '\n'
#define MAX 3000010
#define LSOne(n) (n & (-n))

int res,N;
int p[MAX];
int sum[MAX];

class FenwickTree {
private: vi ft;
// recall that vi is: typedef vector<int> vi;
public: FenwickTree(int n) { ft.assign(n + 1, 0); }
    // init n + 1 zeroes
    int rsq(int b) {
    // returns RSQ(1, b)
    int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
    return sum; }
    // note: LSOne(S) (S & (-S))
    int rsq(int a, int b) {
    // returns RSQ(a, b)
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }
    // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
    void adjust(int k, int v) {
    // note: n = ft.size() - 1
    for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    int n,x;
    cin>>n>>x;
    int A[n];
    sum[0]=0;
    FenwickTree ft(n);
    for(int i=0; i<n; i++){
        cin>>A[i];
        //cout<<"A["<<i<<"]"<<A[i]<<" x: "<<x<<endl;
        if(A[i]>=x){
            p[i]=1;
        }else{
            p[i]=-1;
        }
        sum[i+1]=sum[i]+p[i];
        ft.adjust(i+1, sum[i+1])
    }
    /*cout<<"N:"<<N<<endl;
    for(int i=0; i<2*N; i++){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i=0; i<2*N; i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;*/
    int res=0;
    for(int i=1; i<=n; i++){

    }
    cout<<res<<endl;
}


