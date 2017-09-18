#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define endl '\n'
#define MAX 200001
#define INF -1

int n,i,j,r,ma,mm;

vi pset(1000), setSize(1000); int _numDisjointSets;
void initSet(int N) { setSize.assign(N, 1); _numDisjointSets = N;
pset.assign(N, 0); for (int i = 0; i < N; i++) pset[i] = i; }
int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) {
  if (!isSameSet(i, j)) {
    _numDisjointSets--;
    setSize[findSet(j)] += setSize[findSet(i)];
    pset[findSet(i)] = findSet(j); } }
int numDisjointSets() { return _numDisjointSets; }
int sizeOfSet(int i) { return setSize[findSet(i)]; }


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    while(cin>>n>>r &&(n||r)){
        string s1,s2;
        vector<vii> AdjList;
        map<string, int> m;
        int k=0;
        vii x;
        int V=n;
        initSet(n);

        while(n--){
            cin>>s1;
            m.insert(make_pair(s1, m.size()));
        }
        while(r--){
            cin>>s1>>s2;
            i = m[s1];
            j = m[s2];
            unionSet(i,j);
        }
        ma=0;
        for(int i=0;i<V;i++){
            mm = sizeOfSet(i);
            if(mm>ma) ma=mm;
        }
        cout<<ma<<endl;
    }
    return 0;
}

/*

int mm;
        ma=0;
        // inside int main()---no recursion
        for(int s=0; s<V; s++){
            mm=1;
            vi d(V, INF); d[s] = 0;
            queue<int> q; q.push(s);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                // queue: layer by layer!
                //cout<<s<<": ";
                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                    ii v = AdjList[u][j];
                    // for each neighbor of u
                    if (d[v.first] == INF) {
                        // if v.first is unvisited + reachable
                        d[v.first] = d[u] + 1;
                        // make d[v.first] != INF to flag it
                        q.push(v.first);

                        // enqueue v.first for the next iteration

                    }
                    mm++;

                }

            }
            //cout<<m<<endl;
            if(mm>=ma){ ma=mm; }
        }

        */
