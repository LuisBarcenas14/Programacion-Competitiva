#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define MAX 1000001
#define endl "\n"
#define ios ios_base::sync_with_stdio(0); cin.tie(0);

lli i,j;
bool criba[MAX];
vi dig;
int a1,b1,mod;

void generarPrimos(){
    criba[0]=true;
    for(i=2;i<MAX;i++){
        if(!criba[i]){
            for(j=i*i;j<MAX;j+=i){
                criba[j]=true;
            }
        }
    }
}

void digitos(int a, int b){
    while(a){
        mod = a%b;
        if(!criba[mod]){ dig.push_back(mod); }
        a/=b;
    }
}

int main()
{
    generarPrimos();
    cin>>a1>>b1;
    digitos(a1,b1);
    if(dig.size()==0){
        cout<<"0";
    }else{
        cout<<dig.size();
        sort(dig.begin(), dig.end());
        for(i=0;i<dig.size();i++){
            cout<<" "<<dig[i];
        }
        //cout<<endl;
    }
    return 0;
}

