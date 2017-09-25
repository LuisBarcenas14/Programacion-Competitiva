#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
#define endl '\n'
#define ios ios_base::sync_with_stdio(0); cin.tie(0);

int i,j;

lli consulta(int n){
    double x = ((n*log10(n/M_E)+log10(2*M_PI*n)/2.0));
    return floor(x)+1;
}

int main()
{
    ios;
    //freopen("in","r",stdin);
    int a,t;
    cin>>t;
    while(t--){
        cin>>a;
        if(a==1){
            cout<<"1"<<endl;
        }else{
            cout<<consulta(a)<<endl;
        }

    }
    return 0;
}


/*
double o,u;
int res[MAX];
void generarF(){
        o=log(1);
        res[1]=1;
        for(i=2;i<MAX;i++){
            u=o+log(i);
            res[i]= (int) u/diez+1;
            o=u;
        }
}
*/
