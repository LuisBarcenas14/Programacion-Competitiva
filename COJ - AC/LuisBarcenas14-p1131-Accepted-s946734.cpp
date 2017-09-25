#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef long long int lli;
#define ios ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define MAX 500

bool criba[MAX];
vi primos;
lli e,e1,e2,e3,et,d,n1,n2,i,j,d1,d2,d3,dt;
int k,a,b,p;

void generarPrimos(){
    for(i=0;i<MAX;i++){
        criba[i] =true;
    }
    for(i=2;i<MAX;i++){
        if(criba[i]==true){
            primos.push_back(i);
            for(j=i*i;j<MAX;j+=i){
                criba[j] = false;
            }
        }
    }
}

lli exponente(int n, lli p){
    et=0;
    while(n){
        n/=p;
        et+=n;
    }
    return et;
}

void divisores(int n, int b){
    d=1;
    e=0;
    j=0;
    p = primos[j];
    while(p<=n){
        e1 = exponente(n, p);
        e2=e3=0;
        if(p<=b){
            e2 = exponente(b, p);
        }
        if(p<=(n-b)){
            e3 = exponente(n-b, p);
        }
        e1 = e1-e2-e3;
        d = e1==0 ? d : (d*(1+e1));
        //cout<<"N: "<<n<<" D: "<<d<<" P: "<<p<<" E: "<<e<<endl;
        p = primos[++j];
    }
    cout<<d<<endl;
}

int main()
{
    ios;
    generarPrimos();
    while(cin>>a>>b != NULL){//cin>>a>>b != NULL){
        divisores(a,b);
    }
    return 0;
}