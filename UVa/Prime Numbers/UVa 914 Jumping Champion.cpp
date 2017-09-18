#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 1000010
typedef long long int lli;
typedef vector<int> vi;

vi primos;
vi dif;
bool criba[MAX];
lli i,j,n,t,a,b,c;

void sieve(){
    dif.push_back(0);
    for(i=2;i<MAX;i++)if(!criba[i]){
        if(i>2) dif.push_back( i-primos[primos.size()-1] );
        primos.push_back(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    sieve();
    //cout<<dif.size();
    cin>>t;
    while(t--){
        cin>>a>>b;
        i=lower_bound(primos.begin(),primos.end(),a)-primos.begin();
        j=lower_bound(primos.begin(),primos.end(),b)-primos.begin();
        if(primos[j]!=b) j--;

        if(i>=j){
            cout<<"No jumping champion\n";
            continue;
        }

        vi p(j-i);

        copy(dif.begin()+i+1, dif.begin()+j+1, p.begin());

        sort(p.begin(), p.end());

        int maxi=p[0],c=1,cmax=1;
        bool band=false;
        /*
        cout<<primos[i]<<" "<<primos[j]<<endl;
        for(int k=0;k<p.size();k++)
            cout<<p[k]<<" ";
        cout<<endl;
        */
        if(p.size()==0){
            cout<<"No jumping champion\n";
            continue;
        }else if(p.size()==1){
            cout<<"The jumping champion is "<<p[0]<<endl;
            continue;
        }

        for(int k=1;k<p.size();k++){
            if(p[k]==p[k-1]){
                c++;
                if(c==cmax) band=true;
                if(c>cmax){ cmax=c; maxi=p[k]; band=false; }
            }else{
                c=1;
                if(c==cmax) band=true;
                if(c>cmax){ cmax=c; maxi=p[k]; band=false; }
            }
        }
        if(band)
            cout<<"No jumping champion\n";
        else
            cout<<"The jumping champion is "<<maxi<<endl;

    }
    return 0;
}
