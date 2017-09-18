#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl '\n'
//#define rev(x) (~x)

int rev(int n){
    int i=1;
    int r=0;
    while(i<=n){
        //cout<<"n&i: "<<(n&i)<<endl;
        if(!(n&i)){ r+=i; }
        i<<=1;
    }
    return r;
}

void bit-reverse-copy(vi a, vi &A){
    n=a.size();
    A.assign(n, 0);
    for(int k=0; k<=n-1; k++)
        A[rev(k)]=a[k];
}

int main(){
    freopen("in","r",stdin);
    int n;
    vi a,A;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    return 0;
}
