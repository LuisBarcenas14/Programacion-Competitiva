#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define LSOne(i) (i & (-i))
#define endl '\n'
#define MAX 200001

int f[MAX];

class FenwickTree{
private: vi ft;

public:  FenwickTree(int n){ ft.assign(n+1, 0); }

    int rsq(int b){
        int sum=0; for(;b; b-=LSOne(b)) sum+=ft[b];
        return sum;
    }

    int rsq(int a, int b){
        return rsq(b) - (a==1 ? 0 : rsq(a-1));
    }

    void adjust(int k, int v){
        for(; k<(int)ft.size(); k+=LSOne(k) ) ft[k]+=v;
    }
};

int main(){
    //freopen("in", "r", stdin);
    int n,i,j,x,y,k=1;
    string s;
    while(cin>>n && n){
        if(k>1){ cout<<endl; }
        cout<<"Case "<<k<<":"<<endl;
        FenwickTree ft(n);
        memset(f, 0, sizeof(f));
        for(i=1; i<=n; i++){
            cin>>f[i];
            ft.adjust(i, f[i]);
        }
        while(cin>>s && s!="END"){
            cin>>i>>j;
            if(s=="S"){
                x=j-f[i];
                ft.adjust(i, x);
                f[i]=j;
            }else{
                cout<<ft.rsq(i,j)<<endl;
            }
        }

        k++;
    }
    return 0;
}
