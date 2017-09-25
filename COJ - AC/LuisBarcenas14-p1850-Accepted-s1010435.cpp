#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define mod 10000
#define endl '\n'

int arr[10000];

class SegmentTree{
    private: vi st, A;
    int n;
    int left(int p){ return p<<1; }
    int right(int p){ return (p<<1)+1; }

    void build(int p, int L, int R){
        if(L==R)
            st[p]=(st[p]+A[L])%mod;
        else{
            build(left(p),L,(L+R)/2);
            build(right(p),(L+R)/2+1,R);
            int p1=st[left(p)], p2=st[right(p)];
            st[p]= (p1 + p2)%mod;//(A[p1] <= A[p2]) ? p1: p2;
        }
    }

    int rmq(int p, int L, int R, int i, int j){
        if(i>R || j<L) return -1;
        if(L>=i && R<=j) return st[p];

        int p1=rmq(left(p), L, (L+R)/2,i,j);
        int p2=rmq(right(p),(L+R)/2+1,R,i,j);

        if(p1==-1) return p2;
        if(p2==-1) return p1;

        return (p1 + p2)%mod;//(A[p1]<=A[p2]) ? p1: p2;
    }

    int update_point(int p, int L, int R, int idx, int new_value) {
        int i=idx, j=idx;

        if(i>R || j<L)
            return st[p];

        if(L==i && R==j){
            A[i]=new_value;
            return st[p]=(st[p]+A[i])%mod;
        }

        int p1,p2;
        p1=update_point(left(p),L,(L+R)/2,idx,new_value);
        p2=update_point(right(p),(L+R)/2+1, R, idx, new_value);

        return st[p]= (p1 + p2)%mod; //(A[])
    }

    public:
        SegmentTree(const vi&_A){
            A=_A; n=(int)A.size();
            st.assign(4*n, 0);
            build(1,0,n-1);
        }

        int rmq(int i, int j){
            return rmq(1,0,n-1,i,j);
        }

        int update_point(int idx, int new_value){
            return update_point(1,0,n-1,idx,new_value);
        }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    int n,u,q,i,j,j2,sum,t;
    cin>>n>>u>>q;
    vi A;
    A.assign(n,0);
    //vi A(arr, arr+n);
    SegmentTree st(A);
    sum=u+q;
    while(sum--){
        cin>>t>>i>>j;
        if(t==1){
            j=j%mod;
            j2=(j*2)%mod;
            i--;
            if(i>=0 && i<n)
                st.update_point(i  ,j2);
            if(i+1>=0 && i+1<n)
                st.update_point(i+1,j );
            if(i-1>=0 && i-1<n)
                st.update_point(i-1,j );
            /*
            for(i=0;i<n;i++){
                printf("%d ",st.rmq(i,i));
            }
            printf("\n");
            */
        }else{
            cout<<st.rmq(i-1,j-1)<<endl;
        }
    }
    return 0;
}
