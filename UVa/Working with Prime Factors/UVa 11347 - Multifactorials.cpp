#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define endl '\n'
#define MAX 1001

bool criba[MAX];
vi primos;
lli i,j,p,sum,e,n;
int pfs[1001][169];
int pf[169];

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.push_back(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
    //cout<<primos.size()<<endl;
    //for(i=0;i<10;i++) { cout<<primos[i]<<" "; }
    //cout<<endl;
    for(i=2;i<MAX;i++){
        j=0; p=2; n=i;
        while(p<=n && p){
            e=0;
            if(n%p==0){
                while(n%p==0){
                    n/=p;
                    e++;
                }
                pfs[i][j]=e;
            }
            p=primos[++j];
        }
    }
}

void sumPf(int n){
    for(int k=0;k<168;k++){
        pf[k] += pfs[n][k];
    }
}

void res(int n, int k, int k2=0){
    if(k2==0){ k2=k; }
    for(i=0;i<168;i++){ pf[i]=0; }
    double d=0.0;
    sum=1;
    bool band=false;
    for(int i=k; i<=n; i+=k2){
        //cout<<"i: "<<i<<endl;
        if(i==1){ continue; }
        sumPf(i);

        //sum*=(pf[i]+1);
    }
    for(int i=0; i<168; i++){
        if(pf[i]!=0){
            //cout<<primos[i]<<"^"<<pf[i]<<" ";
            d+=log10(double(pf[i]+1) );
            if(d>18){ band=true; break; }
            sum*=(pf[i]+1);
        }
    }

    if(band)
        cout<<"Infinity"<<endl;
    else
        cout<<sum<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    sieve();
    int n,t,k,diez;
    string s;
    cin>>t;
    for(int j=1; j<=t; j++){
        cin>>s;
        cout<<"Case "<<j<<": ";
        n=k=0;
        diez=1;
        for(int l=s.size()-1;l>=0;l--){
            if(s[l]=='!'){ k++; }
            else{ n+=diez*(s[l]-'0'); diez*=10; }
        }
        if(n%k==0)
            res(n,k);
        else
            res(n, n%k, k);
    }
    return 0;
}
