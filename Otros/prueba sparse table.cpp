#include<bits/stdc++.h>
using namespace std;

#define MAX_N 1000
#define LOG_TWO_N 10
#define endl '\n'
// adjust this value as needed
// 2^10 > 1000, adjust this value as needed

const int K=16;

class RMQ {
// Range Minimum Query
private:
    int _A[MAX_N], SpT[MAX_N][LOG_TWO_N];
public:
    RMQ(int n, int A[]) {
        // constructor as well as pre-processing routine
        for (int i = 0; i < n; i++) {
            _A[i] = A[i];
            SpT[i][0] = A[i]; // RMQ of sub array starting at index i + length 2^0=1
        }
        // the two nested loops below have overall time complexity = O(n log n)
        for (int j = 1; (1<<j) <= n; j++) // for each j s.t. 2^j <= n, O(log n)
            for (int i = 0; i + (1<<j) - 1 < n; i++){
                SpT[i][j] = SpT[i][j-1]+SpT[i+(1<<(j-1))][j-1];
                cout<<"i: "<<i<<" j: "<<j<<" value: "<<SpT[i][j]<<endl;
            }
    }
    long long query(int i, int j) {
        long long answer=0;
        for(int k=K; k>=0; k--){
            if( i+(1<<k)-1 <= j){
                answer+=SpT[i][k];
                i+=1<<k;
            }
        }
        return answer;
    }
};

int main(){
    //freopen("outsp","w",stdout);
    int A[]={18,17,13,19,15,11,20};
    RMQ r(7, A);
    int i,j;
    while(cin>>i>>j){
        //cout<<A[r.query(i,j)]<<endl;
        cout<<r.query(i,j)<<endl;
    }
    return 0;
}
