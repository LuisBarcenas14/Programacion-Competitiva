#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define endl '\n'
#define MAX 10000001

bool criba[MAX];
lli i,j,p,a,b,t,n;
vector<int> primos;
vector<int> an;
int f[]={ 1,1,2,6,24,120,720,5400,40320};

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.push_back(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
}

void anagram(){
    j=0;
    p=primos[j];
    lli l=10,li=1;
    while(j<primos.size()){
        //if(p>l){ l*=10; l1++; }
        string s,r;
        bool band=true;
        stringstream ss0;
        ss0<<p;
        ss0>>s;
        lli k=f[s.length()];
        while(k--){
            //cout<<s<<endl;
            stringstream ss;
            ss<<s;
            ss>>a;
            if(criba[a]){ band=false; break; }
            next_permutation(s.begin(), s.end());
        }

        if(band)
            an.push_back(p);
        p=primos[++j];
    }
}

int main(){
    sieve();
    anagram();
    //cout<<an[an.size()-1]<<endl;
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    string s,r;
    bool band=true;
    while(cin>>n && n){
        if(n==1){ cout<<"2\n"; continue; }
        j=lower_bound(an.begin(), an.end(), n+1)-an.begin();
        if(j>=an.size())
            cout<<0<<endl;
        else{
            lli d=1;
            while(n>=d){
                d*=10;
            }
            //d/=10;
            //cout<<"d:"<<d<<endl;
            if(an[j]<d){
                cout<<an[j]<<endl;
            }else{
                cout<<"0"<<endl;
            }
        }
    }
    return 0;

}
