#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef long long ll;
#define endl '\n'
#define MAX 50001

const int REP = 1000000;
viii uno;
vector<viii> AdjList(MAX, uno);
vector<viii> oAdjList(MAX, uno);
vi dfs_num(MAX);
vi odfs_num(MAX);
bool band;
double maxi;

double monteCarlo(int x, int dif){
    ll sum=0,r;
    for(int i=0; i<REP; i++){
        r = (random() %dif)+x;
        sum+=r;
    }
    cout<<"monte carlo x: "<<x<<" dif: "<<dif<<" sum:"<<sum<<" - res: "<<double(sum)/double (REP)<<endl;
    return double(sum)/double (REP);
}

void dfs(int u, int d){
    dfs_num[u]=1;
    if(u==d) band=true;
    if(band){
        //cout<<(u+1)<<", ";
        return;
    }
    for(int j=0; j<(int)AdjList[u].size() && !band; j++){
        iii v = AdjList[u][j];

        if(dfs_num[v.first]  == 0)
            dfs(v.first, d);

        if(band){
            //cout<<(u+1)<<", ";
            double ans = monteCarlo(v.second.first, v.second.second-v.second.first);
            maxi = ans > maxi ? ans : maxi;
            return;
        }
        //cout<<(u+1)<<", ";
    }


}

int main(){
    //for(int i=0; i<20; i++)
    //    cout<<random()%100<<endl;
    freopen("inK", "r", stdin);
    int n,q,a,b,x,y;
    for(int i=0; i<20; i++){
        int r = random()%100;
        cout<<r<<", ";
    }
    while(cin>>n){
        AdjList = oAdjList;
        for(int i=0; i<n-1; i++){
            cin>>a>>b>>x>>y;
            AdjList[a-1].push_back(iii(b-1, ii(x,y)));
            AdjList[b-1].push_back(iii(a-1, ii(x,y)));
        }
        for(int i=0; i<n; i++){
            cout<<"nodo "<<(i+1)<<" aristas: ";
            for(int j=0; j<AdjList[i].size(); j++){
                cout<<(AdjList[i][j].first+1)<<", ";
            }
            cout<<endl;
        }
        cin>>q;
        while(q--){
            cin>>a>>b;
            dfs_num=odfs_num;
            cout<<"Camino de "<<a<<" a "<<b<<":\n";
            band=false;
            maxi=-1;
            dfs(a-1, b-1);
            cout<<maxi<<endl;
        }
    }
    return 0;
}


