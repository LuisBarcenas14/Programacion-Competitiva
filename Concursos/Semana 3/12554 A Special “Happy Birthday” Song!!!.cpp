#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define endl '\n'
#define MAX 200001

int n,i,j;
string a[101];

int main(){
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    cin>>n;
    vector<string> r;
    string x[]={"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you",
                "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    if(n>16){
        bool b=false;
        for(i=0,j=0; i<16||!b; i++, j=(j+1)%n){
            i%=16;
            if(j==n-1) b=true;
            cout<<a[j]<<": "<<x[i]<<endl;
        }
    }else{
        for(i=0,j=0;i<16; i++, j=(j+1)%n){
            cout<<a[j]<<": "<<x[i]<<endl;
        }
    }
    return 0;
}
