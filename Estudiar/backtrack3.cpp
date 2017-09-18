#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int lli;
#define endl '\n'
#define MAX 10
#define MAXP 3000010

bool criba[MAXP];
vi primos;
lli i,j;

void sieve(){
    for(i=2;i<MAXP;i++) if(!criba[i]){
        primos.push_back(i);
        for(j=i*i;j<MAXP; j+=i)
            criba[j]=true;
    }
}

bool is_solution(int n, int s, int m){
    return n==s && m==0;
}


string cad(int n){
    string s;
    stringstream ss;
    ss<<n;
    ss>>s;
    return s+" ";
}

bool finished;


void backtrack(vi a, int k, int n, int s, int m, string x){
    int c[MAX];
    int ncand;
    int i;
    //cout<<"s: "<<s<<" k: "<<k<<" m: "<<m<<endl;
    if(finished) return;

    if(is_solution(n,s,m)){
        //cout<<"solved\n";
        //process_solution(a,s);
        cout<<x<<endl;
        finished=true;
        //return;
    }else{
        for(i=k;i>=0;i--){

            if(s+a[i]<=n &&m>=0){
                //v.push_back(a[i]);
                backtrack(a, i, n, s+a[i], m-1, x+cad(a[i]) );//x+cad(a[i])
                if(finished) return;
            }else if(i>0 && s+a[i-1]<=n && m>=0){
                //v.push_back(a[i-1]);
                backtrack(a, i-1, n, s+a[i-1], m-1, x+cad(a[i]) );
                if(finished) return;
            }

        }
    }
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    sieve();
    cout<<"primos "<<primos.size()<<endl;
    int n;
    for(n=1; n<=10000000; n++){
        int b = lower_bound(primos.begin(), primos.end(), n/4+10)-primos.begin();
        //cout<<b<<" "<<primos[b]<<endl;
        string x="";
        int s=0,m=4;
        finished=false;
        if(primos[b]==0){
            cout<<"Impossible.\n"<<endl;
        }else{
            backtrack(primos,b,n,s,m,x);
            if(!finished)
                cout<<"Impossible.\n";
        }
        //
    }

    return 0;
}

