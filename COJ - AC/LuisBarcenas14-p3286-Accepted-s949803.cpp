#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef long long int lli;
#define MAX 10001
#define mod 49995041
#define endl "\n"
#define ios ios_base::sync_with_stdio(0); cin.tie(0);

lli x,y,d;
lli c1,c;
int i;
lli f[MAX];
int t, n, m, a, b;


class UnionFind {
// OOP style
public: vi rank;
private: vi p;
public: int _numDisjointSets;
// remember: vi is vector<int>
public:
    UnionFind(int N) { rank.assign(N, 0); _numDisjointSets = N;
        p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    //int sizeOfSet(int i) { return setSize[findSet(i)]; }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            _numDisjointSets--;
            // if from different set
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;
            // rank keeps the tree short
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++; }
} } };

void factorial(){
    f[0] = 1;
    f[1] = 1;
    for(i=2;i<MAX;i++){
        f[i] = (f[i-1]*i)%mod;
    }
}

void extendedEuclid(int a, int b){
    if(b == 0){ x=1; y=0; d=a; return; }
    extendedEuclid(b, a%b);
    int x1 = y;
    int y1 = x - (a/b)*y;
    x = x1;
    y = y1;
}

void comb(int n, int r){
    c1 = (f[r]*f[n-r])%mod;
    extendedEuclid(c1, mod);
    //cout<<"n "<<f[n]<<" r "<<f[r]<<" x "<<x<<endl;
    x = x>0 ? x : x+mod;
    c = (f[n]*x)%mod;
    c = c>0 ? c : c+mod;
}

int main()
{
    //ios;
    factorial();
    cin>>t;
    while(t--){
        cin>>n>>m;
        UnionFind u(n);
        while(m--){
            cin>>a>>b;
            u.unionSet(a-1,b-1);
        }
        if(u._numDisjointSets==1){
            cout<<"0"<<endl;
        }else{
            comb(u._numDisjointSets, 2);
            cout<<c<<endl;
        }
    }
    return 0;
}
