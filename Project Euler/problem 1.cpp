#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int MAX = 1000;
ll s=0;

void pre(){
    for(int i=2; i<MAX; i++){
        if(i%3==0 || i%5==0)
            s+=i;
    }
}

int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    pre();
    cout<<s<<endl;
}
