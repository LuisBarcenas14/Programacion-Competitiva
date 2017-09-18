#include <bits/stdc++.h>
using namespace std;
#define endl '\n'



int main(){
    set<int> conj;
    conj.insert(10);
    conj.insert(20);
    conj.insert(30);
    set<int>::iterator ik;
    ik=conj.lower_bound(19);
    //auto it = distance(conj.begin(), ik);
    cout<<*ik<<endl;
    //cout<<k<<endl;
    return 0;
}
