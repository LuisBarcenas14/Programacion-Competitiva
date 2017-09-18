#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 4010
#define MAX2 16000010

int A[MAX];
int B[MAX];
int C[MAX];
int D[MAX];
int Aux1[MAX2];
int Aux2[MAX2];

void howQuadruplets(int n){
    int k=0, quadruplets=0, ocurrences;
    //Calculamos todas las combinaciones de A y B (A producto cruz B) y todas las combinaciones de C y D (C producto cruz D)
    for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            Aux1[k]=A[i]+B[j];
            Aux2[k]=C[i]+D[j];
            k++;
        }
    }
    //Ordenamos las combinaciones de C y D
    sort(Aux2, Aux2+k);
    //Encontrar cuantas veces esta -Aux1[i] en el arreglo Aux2 para eso utilizamod búsqueda binaria
    for(int i=0;i<k;i++){
        ocurrences=0;
        int low=lower_bound(Aux2, Aux2+k, -Aux1[i])-Aux2;
        int up=upper_bound(Aux2, Aux2+k, -Aux1[i])-Aux2;
        if(Aux1[i]+Aux2[low]==0){
            ocurrences=up-low;
        }
        quadruplets+=ocurrences;
    }
    cout<<quadruplets<<endl;
}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in1152", "r", stdin);
    //freopen("out1152", "w", stdout);
    int t,n,a,b;
    cin>>t;
    for(int j=0;j<t;j++){
        cin>>n;
        if(j>0){ cout<<endl; }
        for(int i=0;i<n;i++){
            cin>>A[i]>>B[i]>>C[i]>>D[i];
        }
        howQuadruplets(n);
    }
    return 0;
}

