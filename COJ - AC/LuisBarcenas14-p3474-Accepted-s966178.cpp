#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long int lli;
#define ios ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 2010
#define endl '\n'

lli uno[MAX];
lli dos[MAX];
lli res[MAX];
int n, m, nt, mt,ni, mi, t;
int i,j;

void multiplicacion(lli uno[MAX], lli dos[MAX]){
    n--; m--;
    nt=0;
    for(i=0;uno[i]!='\0';i++){
        mt=m;
        for(j=0;dos[j]!='\0';j++){
            res[i+j] += uno[n]*dos[mt];
            //cout<<"Grado: "<<(j+i)<<" Coeficiente: "<<(uno[n]*dos[mt])<<endl;
            mt--;
        }
        n--;
    }
}

int main()
{
    ios;
    //freopen("in.txt","r",stdin);
    cin>>n;
    ni=n;
    n++;
    i=j=0;
    while(i<n){
        cin>>uno[i];
        i++;
    }
    cin>>m;
    mi=m;
    m++;
    while(j<m){
        cin>>dos[j];
        j++;
    }
    multiplicacion(uno, dos);
    t = ni+mi;
    for(i=t;i>=0;i--){
        cout<<res[i]<<" ";
    }
    return 0;
}
