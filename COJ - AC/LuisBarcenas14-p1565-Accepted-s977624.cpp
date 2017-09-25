#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef vector<int> vi;
typedef long long int lli;
#define endl '\n'
#define ios ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 10000001

lli i,j,t;
lli p, mp, s,e,st,sf;
lli mpt, et;
bool criba[MAX];
vi primos;
lli n,b,r;

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

lli lachida(lli n, lli mp, lli e){
    s=0;
    while(n>=mp){
        n/=mp;
        s+=n;
    }
    return s/e;
}

void fact(lli n, lli b){
    j=0;
    sf=1000000000000000000;
    p=primos[j];
    while(p<=b && p){ //p[ultimo]=0;
        if(b%p==0){
            et=0;
            mpt=p;
            while(b%p==0){
                b/=p;
                //cout<<"MP: "<<mp<<endl;
                et++;
            }
            st = lachida(n,mpt,et);
            if(st<sf){ sf=st; }
        }
        p = primos[++j];
    }
    //cout<<"B: "<<b<<endl;
    if(b!=1){
        mpt=b; et=1;
        st = lachida(n,mpt,et);
        if(st<sf){ sf=st; }
    }
}

int main()
{
    ios;
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    generarPrimos();
    while(cin>>n>>b && (n||b)){
        //cout<<"B: "<<b<<endl;
        fact(n,b);
        cout<<sf<<endl;
        //cout<<"MP: "<<mp<<" E: "<<e<<endl;
    }
    return 0;
}
