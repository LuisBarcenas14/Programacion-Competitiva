#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    //freopen("j-in", "r", stdin);
    set<string> a;
    set<string> b;
    set<string> c;
    string s;
    for(int i=0; i<3; ){
        cin>>s;
        if(s=="FIN"){ i++; continue; }
        switch(i){
            case 0:
                a.insert(s);
                break;
            case 1:
                b.insert(s);
                break;
            case 2:
                c.insert(s);
                break;
        }
    }
    cout<<(a.size()*b.size()*c.size())<<endl;
    return 0;
}
