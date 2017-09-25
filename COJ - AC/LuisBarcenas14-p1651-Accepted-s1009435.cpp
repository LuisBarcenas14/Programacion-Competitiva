#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl '\n'

int arr[10001];

class SegmentTree{
    private: vi st, A;
    int n;
    int left (int p){ return p<<1; }
    int right(int p){ return (p<<1)+1; }

    void build(int p, int L, int R){
        if(L==R)
            st[p]=L;
        else{
            build(left(p), L,(L+R)/2);
            build(right(p), (L+R)/2+1,R);

            int p1=st[left(p)], p2=st[right(p)];

            st[p]=(A[p1]<=A[p2]) ? p1: p2;

        }
    }

    int rmq(int p, int L, int R, int i, int j){
        if(i>R || j<L) return -1;
        if(L>=i && R<=j) return st[p];

        int p1=rmq(left(p), L, (L+R)/2, i,j);
        int p2=rmq(right(p), (L+R)/2+1,R,i,j);

        if(p1==-1) return p2;
        if(p2==-1) return p1;

        return (A[p1] <= A[p2]) ? p1:p2;
    }

    public:
        SegmentTree(const vi &_A){
            A = _A; n=(int)A.size();
            st.assign(4*n,0);
            build(1, 0, n-1);
        }

        int rmq(int i, int j){
            return rmq(1,0,n-1,i,j);
        }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    int n,a,q;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vi A(arr, arr+n);
    SegmentTree st(A);
    cin>>q;
    int i,j,t;
    while(q--){

        cin>>i>>j;
        if(j<i){ t=i; i=j; j=t; }
        cout<<A[st.rmq(i-1,j-1)]<<endl;
    }
    return 0;
}
