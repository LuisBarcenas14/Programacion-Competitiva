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
    string s;

    for(int i=100; i<=999; i++){
        for(int j=100; j<=999; j++){
            ll prod=i*j;
            stringstream ss;
            ss<<prod;
            ss>>s;
            string cop(s);
            reverse(cop.begin(), cop.end());
            if(s==cop )
                u=prod>u ? prod : u;
        }
    }
    cout<<u<<endl;
}

int main(){
    //freopen("in","r",stdin);
    freopen("out","w",stdout);
    pre();
}



