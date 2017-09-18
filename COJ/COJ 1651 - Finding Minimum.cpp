#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 4000010

int N;
int p[MAX];

int sum(int a, int b){
    a+=N; b+=N;
    int s=1<<30,s1,s2,st;
    while(a<=b){
        s1=s2=1<<30;
        if(a%2==1) s1 = p[a++];
        if(b%2==0) s2 = p[b--];
        st = s1<s2 ? s1 : s2;
        s = s<st ? s : st;
        a/=2; b/=2;
        //cout<<"a: "<<a<<" b: "<<b<<" s: "<<s<<endl;
    }
    return s;
}

void add(int k, int x){
    k+=N;
    p[k]=x;
    for(k/=2; k>=1; k/=2){
        p[k]=p[2*k]<p[2*k+1] ? p[2*k] : p[2*k+1];
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
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,a,b;
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    for(int i=0; i<MAX; i++){
        p[i]=1<<30;
    }
    cin>>n;
    N=pot2(n);
    //cout<<"N: "<<N<<endl;
    for(int i=0; i<n; i++){
        cin>>a;
        add(i, a);
    }
    cin>>q;
    while(q--){
        cin>>a>>b;
        if(a>b){ swap(a,b); }
        a--; b--;
        //cout<<"a: "<<a<<" b: "<<b<<endl;
        cout<<sum(a, b)<<endl;
    }
    /*cout<<"Arreglo P\n";
    for(int i=0; i<2*N; i++){
        printf("%3d",i);
    }
    printf("\n");
    for(int i=0; i<2*N; i++){
        printf("%3d",p[i]);
    }
    cout<<endl;//*/

    return 0;
}


