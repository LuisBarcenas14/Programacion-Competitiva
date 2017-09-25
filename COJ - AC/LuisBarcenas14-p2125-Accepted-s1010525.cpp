#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n'
#define INF 10000000
int arr[100001];

class SegmentTree{
    private: vi st, A;
    int n;
    int left (int p){ return p<<1; }
    int right(int p){ return (p<<1)+1; }

    void build(int p, int L, int R){
        if(L==R)
            st[p]=A[L];
        else{
            build(left(p), L,(L+R)/2);
            build(right(p), (L+R)/2+1,R);

            int p1=st[left(p)], p2=st[right(p)];

            st[p]=p1*p2;
        }
    }

    int rmq(int p, int L, int R, int i, int j){
        if(i>R || j<L) return INF;
        if(L>=i && R<=j) return st[p];

        int p1=rmq(left(p) ,L,(L+R)/2,i,j);
        int p2=rmq(right(p),(L+R)/2+1,R,i,j);

        if(p1==INF) return p2;
        if(p2==INF) return p1;

        return p1*p2;
    }

    int update_point(int p, int L, int R, int idx, int new_value){
        int i=idx, j=idx;

        if(i>R || j<L)
            return st[p];

        if(L==i && R==j){
            A[i]=new_value;
            return st[p]=A[i];
        }

        int p1,p2;
        p1=update_point(left(p) ,L,(L+R)/2,idx,new_value);
        p2=update_point(right(p),(L+R)/2+1,R,idx,new_value);

        return st[p]=p1*p2;
    }

    public:
        SegmentTree(const vi &_A){
            A=_A; n=(int)A.size();
            st.assign(4*n,0);
            build(1,0,n-1);
        }

        int rmq(int i, int j){
            return rmq(1,0,n-1,i,j);
        }

        int update_point(int idx, int new_value){
            return update_point(1, 0, n-1, idx, new_value);
        }
};

int signo(int x){
    if(x>0)
        return 1;
    if(x<0)
        return -1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int n,q,i,j,x,r,a;
    char c;
    while(cin>>n>>q){
        for(i=0;i<n;i++){
            cin>>a;
            x=signo(a);
            arr[i]=x;
        }
        vi A(arr, arr+n);
        SegmentTree st(A);
        while(q--){
            cin>>c>>i>>j;
            if(c=='C'){
                x=signo(j);
                st.update_point(i-1,x);
            }else{
                r= st.rmq(i-1,j-1);
                switch(r){
                    case 1:
                        cout<<'+';
                        break;
                    case -1:
                        cout<<'-';
                        break;
                    case 0:
                        cout<<'0';
                        break;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
