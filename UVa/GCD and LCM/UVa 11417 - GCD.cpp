#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    while(cin>>N && N){
        long long G=0;
        int i,j;
        for(i=1;i<N;i++)
            for(j=i+1;j<=N;j++)
                G+=__gcd(i,j);
        cout<<G<<endl;
    }
    return 0;
}
