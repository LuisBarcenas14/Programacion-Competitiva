#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

string c="cloudy", s="sunny", r="rainy";

int main(){
    //freopen("in","r",stdin);
    int d, ans=0;
    string x;
    string prev[4];
    cin>>d;
    cin>>x;
    prev[0]=x;
    if(x==s)
        ans++;
    for(int i=1, j=1, k=0; i<d; i++, j=(j+1)%4, k=(k+1)%4){
        cin>>x;
        prev[j] = x;
        if(x==s && prev[k]==s)
            ans++;
        else if(x==r && prev[k]==r)
            ans++;
        else if(x==r && i>2 && prev[(i-1)%4]==c && prev[(i-2)%4]==c && prev[(i-3)%4]==c)
            ans++;
        else if(x==c && prev[k]==c && !(i>2 && prev[(i-1)%4]==c && prev[(i-2)%4]==c && prev[(i-3)%4]==c))
            ans++;

    }
    cout<<ans<<endl;
}
