#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl '\n'

class UnionFind {
// OOP style
private: vi p, rank;
// remember: vi is vector<int>
public:
    UnionFind(int N) { rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }

    void imp(){
        for(int i=0;i<rank.size();i++){ cout<<p[i]<<" "; }
        cout<<endl;
     }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            // if from different set
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;
            // rank keeps the tree short
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
 };


int main(){
    UnionFind u(20);
    //u.imp();
    u.unionSet(1,3);
    //u.imp();
    u.unionSet(2,3);
    //u.imp();
    u.unionSet(2,5);
    u.unionSet(5,7);
    u.unionSet(16,17);
    u.unionSet(18,19);
    u.unionSet(19,15);
    u.unionSet(15,18);
    //8 inserts


    //u.imp();
    cout<<u.isSameSet(5,6)<<endl;
    cout<<u.isSameSet(7,1)<<endl;
    cout<<u.isSameSet(1,5)<<endl;
    cout<<u.isSameSet(18,16)<<endl;
    cout<<u.isSameSet(2,13)<<endl;
    cout<<u.isSameSet(14,15)<<endl;
    cout<<u.isSameSet(19,19)<<endl;
    cout<<u.isSameSet(15,16)<<endl;
    cout<<u.isSameSet(16,18)<<endl;
    return 0;
}
