#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define end '\n'
#define VISITED 1
#define UNVISITED 0

vi dfs_num;
vector<bool> friends;
vector<vii> AdjList;
int i,j;
int sum,maxi;

void dfs(int u, int dist){
    //dfs_num[u]=VISITED;
    //cout<<"visitado: "<<u+1<<" nivel: "<<level<<" distancia: "<<dist<<" maximo: "<<maxi<<endl;
    //cout<<"suma: "<<sum<<endl;
    for(int j=0; j<(int)AdjList[u].size(); j++){
        ii v=AdjList[u][j];
        //if(dfs_num[v.first]==UNVISITED){
            //cout<<u+1<<" - "<<v.first+1<<" : "<<level+1<<endl;

            dfs(v.first, dist+v.second );
            if(friends[v.first]){ friends[u]=true; }
            if(friends[v.first]){ sum+=v.second; maxi=max(maxi, dist+v.second); }
        //}
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int n,e,f;
    while(cin>>n>>f){
        sum=0;
        AdjList.assign(n,vii());
        dfs_num.assign(n,0);
        friends.assign(n,false);
        int d;
        n--;
        while(n--){
            cin>>i>>j>>d;
            AdjList[i-1].push_back(make_pair(j-1,d));
        }
        //cout<<"antes";
        while(f--){
            cin>>i;
            friends[i-1]=true;
        }
        maxi=-1;
        dfs(0,0);
        //cout<<"suma final: "<<sum<<" max: "<<maxi<<endl;
        if(sum>0){
            cout<<sum-maxi<<'\n';
        }else{ cout<<"0"<<endl; }
    }
    return 0;
}
