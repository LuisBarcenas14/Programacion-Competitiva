#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,r;
    vector<int> divs;
    while(cin>>n && n){
        divs.clear();
        int c=0;
        for(int i=1; i*i<=n; i++){
            if(n%i==0){
                divs.push_back(i);
                c++;
                if(n/i != i){
                    divs.push_back(n/i);
                    c++;
                }
            }
        }
        //for(int i=0; i<divs.size(); i++){ cout<<divs[i]<<" "; }
        //cout<<endl;
        //sort(divs.begin(), divs.end());
        for(int i=2; i<divs.size()-1; i++){
            for(int j=i+1; j<divs.size(); j++)
                if(__gcd(divs[i], divs[j])==1)
                    c++;
        }
        cout<<n<<" "<<c<<endl;
    }
}
