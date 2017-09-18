#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define endl '\n'
#define pb push_back
#define MAX 100001

int a[MAX];
int temp[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("in","r",stdin);
    int t,k,x,sum=0,s=0,dif,mini=1<<30,omini=mini,j,i;
    cin>>t>>k;

    for(i=0;i<t;i++){
        cin>>a[i];
        //if(i==0){ x=a[i]; }
        sum+=a[i];
        //cout<<"-sum: "<<sum<<" s: "<<s<<" mini: "<<mini<<endl;
        if(sum<k){ continue; }
        for(j=s; sum>k; j++){
            sum-=a[j];
            s=j+1;
            //cout<<"sum: "<<sum<<" s: "<<s<<" mini: "<<mini<<endl;
        }
        if(sum==k){
            dif=i-j+1;
            if(dif<mini){ mini=dif; }
        }
    }
    if(mini==omini)
        cout<<"-1"<<endl;
    else
        cout<<mini<<endl;
    return 0;
}
