#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define endl '\n'
#define MAX 200001
#define INF -1

int n,i,j,r,ma,mm;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    string s,s1;
    int f[11];
    f[0]=1;
    for(i=1;i<=10;i++)
        f[i]=i*f[i-1];
    cin>>n;

    while(n--){
        vector<string> c;
        cin>>s;
        j=f[s.size()];
        while(j--){
            c.push_back(s);
            next_permutation(s.begin(), s.end());
        }
        sort(c.begin(), c.end());
        c.erase( unique( c.begin(), c.end() ), c.end() );
        //c.erase();

        for(int i=0;i<c.size();i++)
            cout<<c[i]<<endl;

        cout<<endl;
    }

    return 0;
}

