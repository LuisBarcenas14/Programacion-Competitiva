#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef vector<int> vi;
//1 10 11 12 13 20

int sumT(vi arr, int n){
    int sum=0,dif;
    for(int i=0; i<2*n-2; i+=2){
        dif=arr[i+1]-arr[i];
        sum+=dif;
    }
    return sum;
}


int main(){
    //freopen("in","r",stdin);
    int dif=0, sum=0, mini=1<<30;
    vi arr;
    vi arr2;
    int n,a;
    cin>>n;
    for(int i=0; i<n*2; i++){
        cin>>a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<n*2; i++){
        for(int j=i+1; j<2*n; j++){
            arr2 = arr;
            arr2.erase(arr2.begin()+i);

            arr2.erase(arr2.begin()+j-1);
            dif = sumT(arr2, n);
            if(dif<mini) mini=dif;
        }
    }
    cout<<mini<<endl;
    return 0;
}
