#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int lli;
#define endl '\n'
#define MAX 1000000
#define MAXPOT 78498
bool criba[MAX];
vi primos;
lli i,j,p,ma,jma,nn,l;
int pot[MAXPOT][2];

void sieve(){
    int k=0;
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.push_back(i);
        pot[k++][0]=i;
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
    //for(i=0;i<10;i++) cout<<primos[i]<<" ";
    //cout<<primos.size()<<endl;
}

void pf(lli n, int e){
    j=0,p=primos[j];
    while(p<=n ){
        if(n%p==0){
            if(p>ma){ ma=p; jma=j; }
            int et=0;
            l++;
            while(n%p==0){
                n/=p;
                et++;
            }
            pot[j][1]+=et*e;
        }
        p=primos[++j];
    }

    j=0;
    p=primos[j];
    while(p<=ma){

        p=primos[++j];
    }
}

lli pow(int n, int e){
    lli r=1,b=n;
    while(e--){
        r*=b;
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    sieve();
    string s;
    int n,e;

    while(getline(cin, s) && s!="0"){
        stringstream ss;
        ss<<s;
        for(i=0;i<MAXPOT;i++){
            pot[i][1]=0;

        }
        l=jma=ma=0;
        nn=1;
        while(ss>>n>>e){
            //cout<<n<<" "<<e<<endl;
            nn*=pow(n,e);
        }
        pf(nn-1,1);
        //cout<<"ok"<<endl;
        for(; jma>=0 && l>1;jma--){
            if(pot[jma][1]!=0){
                cout<<pot[jma][0]<<" "<<pot[jma][1]<<" ";
                l--;
            }
        }
        for(; jma>=0;jma--){
            if(pot[jma][1]!=0){
                cout<<pot[jma][0]<<" "<<pot[jma][1];
            }
        }
        cout<<endl;
    }

    return 0;
}
