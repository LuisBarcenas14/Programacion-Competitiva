#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 4000010

int N;
int p[MAX];

int sum(int a, int b){
    a+=N; b+=N;
    int s=-1,s1,s2,st;
    while(a<=b){
        s1=s2=-1;
        if(a%2==1) s1 = p[a++];
        if(b%2==0) s2 = p[b--];
        st = s1>s2 ? s1 : s2;
        s = s>st ? s : st;
        a/=2; b/=2;
        //cout<<"a: "<<a<<" b: "<<b<<" s: "<<s<<endl;
    }
    return s;
}

void add(int k, int x){
    k+=N;
    p[k]=x;
    for(k/=2; k>=1; k/=2){
        p[k]=p[2*k]>p[2*k+1] ? p[2*k] : p[2*k+1];
    }
}

int pot2(int n){
    int i=0;
    while(n){
        n/=2;
        i++;
    }
    return 1<<i;
}

int main(){
    int q,a,b;
    freopen("segmtree.in", "r", stdin);
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>a;
        add(i, a);
    }
    cin>>q;
    while(q--){
        cin>>a>>b;
        cout<<"a: "<<a<<" b: "<<b<<endl;
        cout<<sum(a, b)<<endl;
    }
    for(int i=0; i<2*N; i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;//*/

    return 0;
}

