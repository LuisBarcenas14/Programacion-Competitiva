#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int MAX = 1000000;
ll s=0;
int a,b,t;
ll i,j;
bool criba[MAX];
vector<int> primos;
ll u;

void pre(){
    ll v1=0, v2=0,a=0;
    for(int i=1; i<=100; i++){
        a+=i;
        v1+=i*i;
    }
    v2=a*a;
    cout<<(v2-v1)<<endl;
}

int main(){
    //freopen("in","r",stdin);
    freopen("out","w",stdout);
    pre();
}




