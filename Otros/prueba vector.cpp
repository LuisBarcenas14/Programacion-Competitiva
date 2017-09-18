#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<int> W[10];

int main(){
    W[2].push_back(2);
    W[2].push_back(3);
    W[2].push_back(5);
    cout<<(W[2][0])<<endl;
    cout<<(upper_bound(W[2].begin(), W[2].end(), 7)-W[2].begin())<<endl;

    return 0;
}
