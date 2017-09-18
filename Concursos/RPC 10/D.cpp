#include <bits/stdc++.h>
using namespace std;
typedef map<int, map<int, map<int, map<int, int> > > > map4;
typedef map<int, map<int, map<int, int> > > map3;
typedef map<int, map<int, int> > map2;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<vvi, int> ps;
typedef vector<ps> vps;
#define endl '\n'

int N,K,V;
int sq[510][510];
int a,b,c,d,p;
map3 gmapa3;
map2 gmapa2;
map<int, int> gmapa1;

bool insertar2(map4 &gmapa, vii &arr, int &v){
    if(!gmapa[a][b][c].count(d)){
        gmapa[a][b][c][d]=v;
        //cout<<"INSERTADO v: "<<v<<" p: "<<p<<endl;
        return true;
    }else{
        v = gmapa[a][b][c][d];
        if(arr[v].first<p)
            arr[v].first=p;
        //cout<<"YA EXISTE v: "<<v<<" p: "<<p<<" cuantos: "<<arr[v].second<<" mayor: "<<arr[v].first<<endl;
        return false;
    }
}

int encontrar2(map4 &gmapa, vii &arr, int &v){
    v = gmapa[a][b][c][d];
    //cout<<v<<endl;
    if(!gmapa[a][b][c].count(d)){
        //cout<<"NO d"<<endl;;
        return 0;
    }else{
        V++;
        //cout<<"f "<<arr[v2].first<<" s "<<arr[v2].second<<endl;
        //return arr[v2].first*arr[v2].second;
        return arr[v].first;
    }
}

void rotar(int &a, int &b, int &c, int &d){
    int a2=a,b2=b,c2=c,d2=d;
    a = b2;
    b = d2;
    c = a2;
    d = c2;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in", "r", stdin);
    while(cin>>N>>K && N){
        //Variables a usar
        V=0;
        long long res =0;
        map4 gmapa;
        vps vec;
        vii arr;
        arr.push_back(make_pair(0,0));
        int v=1, c;
        //Leer cuadrados 2x2
        for(int i=0; i<K; i++){
            cin>>a>>b>>c>>d>>p;
            bool band=true;
            for(int k=0; k<4; k++){
                band &= insertar2(gmapa, arr, v);
                rotar(a,b,c,d);
            }
            if(!band) arr[v].second++;
            if(band){
                arr.push_back(make_pair(p,1));
                v++;
            }

            //cout<<"v: "<<v<<" cuantos: "<<arr[2].second<<" mayor: "<<arr[2].first<<endl;
        }

        //Leer cuadrado NxN
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++)
                cin>>sq[i][j];
        }
        //Encontrar respuesta
        bool bandRes=true;
        for(int i=0; i<N && bandRes; i+=2){
            for(int j=0; j<N && bandRes; j+=2){
                a=sq[i][j]; b=sq[i][j+1]; c=sq[i+1][j]; d=sq[i+1][j+1];
                //cout<<"a: "<<a<<" b: "<<b<<" c: "<<c<<" d: "<<d<<endl;
                c = encontrar2(gmapa, arr, v);
                //cout<<"I:"<<i<<" J: "<<j<<" c: "<<c<<endl;
                if(v==0)
                    bandRes = false;
                else
                    res+=c;
            }
        }
        if(!bandRes)
            cout<<"-1"<<endl;
        else
            cout<<res<<endl;
        //cout<<"V: "<<V<<" N: "<<N<<" res: "<<res<<endl;
    }
    return 0;
}
