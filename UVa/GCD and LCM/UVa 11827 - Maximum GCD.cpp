#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in", "r", stdin);
    int a,n,m,t;
    string s,s1;
    cin>>t;
    cin.ignore(250, '\n');
    for(int i=1; i<=t; i++){
        getline(cin, s);
        stringstream ss;
        ss<<s;
        vector<int> nums;
        while(ss>>a){
            nums.push_back(a);
        }
        int maxi=-1,g;
        for(int i=0;i<(int) nums.size()-1; i++ ){
            for(int j=i+1; j<(int)nums.size(); j++)
                if( (g=__gcd(nums[i], nums[j]))>maxi )
                    maxi=g;
        }
        cout<<maxi<<endl;

    }
    return 0;
}


