#include <bits/stdc++.h>
using namespace std;
typedef map<int, int>::iterator it;
typedef vector<int> vi;
#define endl '\n'
#define pb push_back

map<int, int> painters;
vi v;

int main(){
    v.pb(1);
    v.pb(3);
    v.pb(5);
    v.pb(7);
    v.pb(9);
    painters[-1]=0;
    painters[1]=10;
    painters[3]=20;

    vector<int>::iterator i = lower_bound(v.begin(), v.end(), 4);
    //cout<<(i->)<<endl;
    it low = painters.lower_bound(2);
    //cout<<(i)<<endl;
    cout<<(low->first)<<" "<<(low->second)<<endl;
    return 0;
}
