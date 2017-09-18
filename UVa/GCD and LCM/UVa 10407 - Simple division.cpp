#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in", "r", stdin);
    int a,n,m,t;
    while(cin>>a && a!=0){
        set<int> nums;
        nums.insert(a);
        while(cin>>a && a!=0){
            nums.insert(a);
        }
        int i=0,g=0,first;
        for(set<int>::iterator it = nums.begin(); it!=nums.end(); ++it, ++i){
            if(i==0){ first=*it; ++it; g=*it-first; --it; continue; }
            //cout<<"it "<<*it<<" g: "<<g<<" ";
            g=__gcd(g, *it-first);
        }
        //cout<<endl;
        cout<<g<<endl;
    }
    return 0;
}



