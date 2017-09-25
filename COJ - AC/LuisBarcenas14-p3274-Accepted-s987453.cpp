#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
#define MAX 1010
#define endl '\n'
#define ios ios_base::sync_with_stdio(0); cin.tie(0);

bool criba[MAX];
vi primos;
int i,j,k;

void generarPrimos(){
    for(i=2;i<MAX;i++){
        if(!criba[i]){
            primos.push_back(i);

            for(j=i*i;j<MAX;j+=i)
                criba[j]=true;
        }
    }
}

void fact(int n){
    i=0;
    j=primos[i];
    k=0;
    while(j*j<=n){
        if(n%j==0){
            k++;
            while(n%j==0){
                n/=j;
            }
        }
        j=primos[++i];
    }
    if(n!=1)
        k++;
    cout<<k<<endl;
}
int main()
{
    ios;
    generarPrimos();
    int t,a;
    cin>>t;
    while(t--){
        cin>>a;
        fact(a);
    }
    return 0;
}
