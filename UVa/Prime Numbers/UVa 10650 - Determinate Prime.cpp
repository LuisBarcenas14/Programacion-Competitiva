#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define MAX 33010//1000010

bool criba[MAX];
vi primos;
lli i,j,p,ans,d1,d2;
vector<vi> dets;

void sieve(){
    int k=0,kv=1;
    criba[1]=true;
    d1=-2;
    d2=-1;
    bool b=false;
    vi det;
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.pb(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }

    for(int i=1;i<primos.size();i++){
        d1=d2; d2=primos[i]-primos[i-1];
        if(d1==d2){
            kv++;
            det.pb(primos[i]);
        }else{
            if(kv>2){
                det.pb(-1);
                dets.pb(det);
            }
            det.clear();
            kv=2;
            det.pb(primos[i-1]);
            det.pb(primos[i]);
        }
    }
    //cout<<"wow"<<endl;
    /*
    for(i=0;i<10;i++){
        for(j=0;dets[i][j]!=-1;j++)
            cout<<dets[i][j]<<" ";
        cout<<endl;
    }
    */

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    sieve();
    int i,j,k,l,t;
    while(cin>>i>>j && (i||j) ){
        if(i>j){ t=i; i=j; j=t; }

        for(k=0; dets[k][dets[k].size()-2]<=j ; k++){
            if(dets[k][0]>=i){
                for(l=0;l<dets[k].size()-2; l++) cout<<dets[k][l]<<" ";
                cout<<dets[k][l]<<endl;
            }
        }

    }
    return 0;
}

