#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define endl '\n'
#define ios ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 5000000

bool criba[MAX];
vector<int> primos;
int fact[2][2];
lli i,j,n;
bool band;

void generarPrimos(){
    for(i=2;i<MAX;i++){
        if(!criba[i]){
            primos.push_back(i);
            for(j=i*i;j<MAX;j+=i){
                criba[j]=true;
            }
        }
    }
    primos.push_back(0);
}

void factorizar(lli n){
    i=0;
    j=primos[i];
    int k=0;
    fact[0][0]=fact[0][1]=0;
    fact[1][0]=fact[1][1]=0;
    band=false;
    while(j*j<=n && j){
        if(n%j==0){
            if(k<2){
                fact[k][0]=j;
            }else if(k==2){
                band=true;
            }
            while(n%j==0){
                if(k<2){ fact[k][1]++; }
                n/=j;
            }
            k++;
        }
        j=primos[++i];
    }
    if(n!=1){
        if(fact[1][0]==0){
            fact[1][0]=n; fact[1][1]=1;
        }
        if(k>=2){
            band=true;
        }
    }
}

int main()
{
    ios;
    generarPrimos();
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        factorizar(n);
        //cout<<fact[0][0]<<" "<<fact[0][1]<<endl;
        //cout<<fact[1][0]<<" "<<fact[1][1]<<endl;
        //cout<<"band: "<<band<<endl;
        if(fact[0][0]==0){
            cout<<"Vasha"<<endl;
            cout<<"0"<<endl;
        }else if(fact[0][1]>=2 && fact[0][0]*fact[0][0]!=n){
            cout<<"Vasha"<<endl;
            cout<< (fact[0][0]*fact[0][0])<<endl;
        }else if(fact[0][1]==2 && fact[1][1]==0 || (fact[0][1]==1 && fact[1][1]==1&&band==false )){
            cout<<"Molek"<<endl;
        }else{
            cout<<"Vasha"<<endl;
            cout<<fact[0][0]*fact[1][0]<<endl;
        }
    }
    return 0;
}

