#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define endl '\n'

const int VISITED = 1;
const int UNVISITED = 0;
const int INF = (int)1e8;
vector<vii> AdjList;
vi dfs_num;
vi o_dfs_num;
int V,U;

void bfs(int s){
    vi d(V, INF); d[s] = 0; //Distancia entre s y los demás nodos
    queue<int> q; q.push(s); //Cola
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            cout<<endl<<"Del nodo "<<u+1<<" visito: ";
            if (d[v.first] == INF) { //No ha sido visitado antes
                d[v.first] = d[u] + v.second; //Distancia desde s a v.first
                cout<<v.first+1<<", ";

                q.push(v.first); //Agregar a la cola los hijos del nodo actual
            }
        }
    }
    for(int i=0; i<V; i++){
        cout<<endl<<"Distancia de "<<s+1<<" a "<<i+1<<" es: "<<d[i];
    }
    cout<<endl;
}

void dfs(int u, int dist) {
    dfs_num[u] = VISITED;

    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];

        cout<<endl<<"Distancia de "<<U+1<<" a "<<v.first+1<<" es: ";
        if (dfs_num[v.first] == UNVISITED){
            cout<<dist+v.second;
            dfs(v.first, dist+v.second);

        }
    }
    cout<<endl;
}

int main(){
    freopen("bfs.in","r",stdin);
    int n, edges, a, b, c, q;
    string recorrido;
    cout<<"Introduzca Número de nodos y aristas:";
    cin>>n>>edges;
    V=n;
    vii x;
    cout<<endl;
    for(int i=0; i<n; i++){
        AdjList.push_back(x);
        o_dfs_num.push_back(0);
    }
    for(int i=0; i<edges; i++){
        cout<<"Introducir nodos conectado y distancia entre nodos: ";
        cin>>a>>b>>c;
        AdjList[a-1].push_back(ii(b-1, c));
        AdjList[b-1].push_back(ii(a-1, c));
        cout<<endl;
    }
    cout<<"Introduzca número de consultas"<<endl;
    cin>>q;
    while(q--){
        cout<<"Introduzca DFS/BFS y el nodo del que desea iniciar el recorrido: ";
        cin>>recorrido>>a;
        cout<<recorrido<<" a "<<a<<endl;
        if(recorrido == "bfs" || recorrido == "BFS")
            bfs(a-1);
        else if(recorrido == "dfs" || recorrido == "DFS"){
            U=a-1;
            dfs_num=o_dfs_num;
            dfs(a-1, 0);
        }
        cout<<endl;
    }
    return 0;
}
