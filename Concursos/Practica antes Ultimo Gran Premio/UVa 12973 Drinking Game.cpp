#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

const int MAX=1000;
bool criba[MAX];
vi primos;
int fact[100];

void sieve(){
    int i,j;
    for(i=2; i<MAX; i++)if(!criba[i]){
        primos.push_back(i);
        for(int j=i*i; j<MAX; j+=i)
            criba[j]=true;
    }
}

void restarF(int n){
    int j=0, p=2;
    while(p<=n){
        while(n%p==0){
            fact[j]--;
            n/=p;
        }
        p=primos[++j];
    }
}

void sumarF(int n){
    int j=0, p=2;
    while(p<=n){
        while(n%p==0){
            fact[j]++;
            n/=p;
        }
        p=primos[++j];
    }
}

bool encontrarF(int n){
    int j=0, p=2,t;
    while(p<=n){
        t=0;
        while(n%p==0){
            t++;
            n/=p;
        }
        if(fact[j]>t)
            return true;
        p=primos[++j];
    }
    return false;
}

int minimo(int n){
    int dif = n-1,r, i=n-1, j=n+1;
    bool b1=true,b2;
    while(b1 || b2){
        b1=encontrarF(i);
        b2=encontrarF(j);
        i--; j++;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("in","r",stdin);
    sieve();
    int n;

    int k=1;
    while(cin>>n && n){
        int a[n];
        memset(fact, 0, sizeof(fact));
        vi res;
        for(int i=0; i<n; i++){
            cin>>a[i];
            sumarF(a[i]);
        }
        sort(a, a+n);
        cout<<"FACT"<<endl;
        for(int i=0; i<n; i++){
            cout<<primos[i]<<" : "<<fact[i]<<endl;
        }
        for(int i=0; i<n; i++){
            bool band = encontrarF(a[i]);
            if(!band){
                res.push_back(a[i]);
                restarF(a[i]);
                cout<<i<<" F- Agregado "<<a[i]<<endl;
            }else{
                int m = minimo(a[i]);
                res.push_back(m);
                restarF(a[i]);
                sumarF(m);
                cout<<i<<" T- Agregado "<<m<<endl;
            }
        }

        sort(res.begin(), res.end());
        cout<<"Case #"<<k<<": ";
        for(int i=0; i<n; i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
        k++;
    }
    return 0;
}

