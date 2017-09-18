#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<int> c;

void pre(){
    int a=1, i=1;
    while(a<=200000){
        c.push_back(a);
        a=i*i;
        i++;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    pre();
    int t,n,i;
    cin>>t;
    while(t--){
        cin>>n;
        i=0;
        while(n>0){
            int j = lower_bound(c.begin(), c.end(), n)-c.begin();
            if(c[j]>n){ j--; }
            int m = n/c[j];
            n -= m*c[j];
            i+=m;
        }
        cout<<i<<endl;
    }
}

