#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define endl '\n'
#define MAX 2000010

int res;

void SlidingWindow(int A[], int n, int x){
    res=0;
    for(int i=0; i<n; i++){
        string s;
        for(int j=i; j<n; j++){
            if(A[j]>=x)
                s = s+'Y';
            else
                s = 'N'+s;
            //cout<<s<<endl;
            int k = ceil( (j-i)/2.0 );
            //cout<<"i: "<<i<<" j: "<<j<<" s: "<<s<<" K: "<<k<<endl;
            if(s[k]=='Y')
                res++;
        }

    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    int n,x;
    cin>>n>>x;
    int A[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    SlidingWindow(A, n, x);
    cout<<res<<endl;
}

