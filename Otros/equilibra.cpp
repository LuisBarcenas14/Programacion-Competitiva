#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<int> arr;

void equilibra(int n, int nivel, int maxi){
  if(n>0 && nivel<=maxi){
    if(n==1 && nivel==maxi){
      arr.push_back(1);
      cout<<"1 ";
    }
    else if(n==1){
      arr.push_back(0);
      cout<<"0 ";
    }
    //cout<<"n: "<<n<<" nivel: "<<nivel<<endl;
    equilibra(n/2+n%2, nivel+1, maxi);
    equilibra(n/2    , nivel+1, maxi);
  }
}

int main(){
    int n =13;
    //vector<int> arr;
    equilibra(n, 0, 4);
    return 0;
}
