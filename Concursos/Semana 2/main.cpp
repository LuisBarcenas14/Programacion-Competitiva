#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define endl '\n'
#define MAX 100010

lli i,j;
bool criba[MAX];
vi primos;

void sieve(){
    for(i=2;i<MAX;i++){
        if(!criba[i]){
            primos.push_back(i);
            for(j=i*i;j<MAX;j+=i)
                criba[j]=true;
        }
    }
}


lli numDiv(lli N) {
    lli j = 0, PF = primos[j], ans = 1;
    while (PF * PF <= N) {
        lli power = 0;
        while (N % PF == 0) { N /= PF; power++; }
        ans *= (power + 1);
        PF = primos[++j];
    }
    if (N != 1) ans *= 2;
    return ans;
}

lli sumDiv(lli N) {
    lli j = 0, PF = primos[j], ans = 1;
    while (PF * PF <= N) {
        lli power = 0;
        while (N % PF == 0) { N /= PF; power++; }
        ans *= ((lli)pow((double)PF, power + 1.0) - 1) / (PF - 1);
        PF = primos[++j];
    }
    if (N != 1) ans *= ((lli)pow((double)N, 2.0) - 1) / (N - 1);
    return ans;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    sieve();
    int t;
    lli a,b,c,sum1=0,sum2=0,k;
    //cout<<primos.size()<<endl;
    //for(int i=0;i<10;i++) cout<<primos[i]<<" ";
    //cout<<primos[primos.size()-1]<<endl;

    cin>>t;
    while(t--){
        sum1=sum2=0;
        cin>>a>>b>>c;
        k=1;
        for(;a<=b;a+=k){
            if(a%c==0){
                if(k==1) k=c;
                sum1+=numDiv(a);
                sum2+=sumDiv(a);
            }
        }
        cout<<sum1<<" "<<sum2<<endl;
    }

    return 0;
}
