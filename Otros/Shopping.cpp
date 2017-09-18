#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int lli;
typedef vector<lli> vlli;
#define endl '\n'
#define MAX 200001

lli maxi;

class SegmentTree {
    private: vlli st, A;
    lli n;
    lli left (lli p) { return p << 1; }
    lli right(lli p) { return (p << 1) + 1; }
    void build(lli p, int L, int R) {
        if (L == R)
        st[p] = L;
        else {
            build(left(p) , L              , (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R          );
            lli p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }

    int rmq(lli p, int L, int R, int i, int j) {
        if (i > R || j < L  || (L >= i && R <= j && A[st[p]]>maxi) ) return -1; //¿Esta dentro de nuestro rango' y ¿Es menor a nuestro dinero actual?
        if (L >= i && R <= j && L==R && A[st[p]] <=maxi){ return st[p]; } //¿Es hoja? Por eso L==R
        else{
            lli p1 = rmq(left(p) , L, (L+R) / 2, i, j);
            lli p2=-1;
            if(p1==-1) //No calculamos la consulta del lado derecho al menos que sea necesario
                p2 = rmq(right(p), (L+R) / 2 + 1, R, i, j);

            if (p2 == -1 && p1!=-1 && A[p1]<=maxi) return p1;
            if (p1 == -1 && p2!=-1 && A[p2]<=maxi) return p2;

            if(p1!=-1 && A[p1]<=maxi)
                return p1;

            return -1;
        }

        lli p1 = rmq(left(p) , L, (L+R) / 2, i, j);
        lli p2=-1;
        if(p1==-1) //No calculamos la consulta del lado derecho al menos que sea necesario
            p2 = rmq(right(p), (L+R) / 2 + 1, R, i, j);

        if (p2 == -1 && p1!=-1) return p1;
        if (p1 == -1 && p2!=-1) return p2;

        if(p1!=-1 && A[p1]<=maxi)
            return p1;
        return -1;
    }

public:
    SegmentTree(const vlli &_A) {
        A = _A; n = (int)A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int n,q,i,j,k;
    lli arr[MAX];
    cin>>n>>q;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vlli A(arr, arr + n);
    SegmentTree st(A);
    while(q--){
        cin>>maxi>>i>>j;
        i--;
        j--;
        while(maxi!=0 && i<=j && (k=st.rmq(i,j))!=-1){
            //printf("maxi: %5d k: %3d arr[k]: %3d\n",maxi,k,arr[k]);
            maxi=maxi%arr[k];
            i=(k+1);
        }
        cout<<maxi<<endl;
    }
    return 0;
}
