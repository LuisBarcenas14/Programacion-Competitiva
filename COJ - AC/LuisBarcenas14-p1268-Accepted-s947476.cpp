#include <vector>
#include <iostream>
using namespace std;
typedef long long int lli;
#define MAX 31700
#define endl "\n"
#define ios ios_base::sync_with_stdio(0);cin.tie(0);

vector<int> primos;
bool criba[MAX];
lli i,j;
int a,p;
bool b1;

void generarPrimos(){
    for(i=2;i<MAX;i++){
        if(!criba[i]){
            primos.push_back(i);
            for(j=i*i;j<MAX;j+=i){
                criba[j]=true;
            }
        }
    }
}

int main()
{
    //ios;
    generarPrimos();
    while(cin>>a){
        if(a==1){
            cout<<"YES"<<endl;
        }else if(a==4){
            cout<<"NO"<<endl;
        }else{
            i=0;
            p = primos[i];
            b1 = false;
            while(p*p<=a){
                if(a%p==0 && a!=p){ b1=true; break; }
                p = primos[++i];
            }
            if(b1){ cout<<"YES"<<endl; }else{ cout<<"NO"<<endl; }
        }
    }
    return 0;
}
