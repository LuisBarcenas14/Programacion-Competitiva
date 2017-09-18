#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("in","r",stdin);
    int n;
    int q;
    cin >> n >> q;
    vi a(n);
    //vector<vi> mods;
    //vi v;
    //for(int a_i = 0; a_i < 40001; a_i++){ mods.push_back(v); }
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
       //mods[a[a_i]].push_back(make_pair(a_i, ))
    }

    for(int a0 = 0; a0 < q; a0++){
        int left;
        int right;
        int x;
        int y;
        cin >> left >> right >> x >> y;
        // your code goes here
        int count=0;
        for(int i=left;i<=right;i++)
            if(a[i]%x==y)
                count++;
        cout<<count<<"\n";
    }
    return 0;
}

