#include <vector>
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define MAX 1000010
#define endl "\n"
#define ios ios_base::sync_with_stdio(0); cin.tie(0);

vi primos;
int criba[MAX], f[MAX];
lli i, j;
int a,b,k,c,p,z;
bool band;
int mu [MAX];

void generarPrimos(){
	for(i=0;i<MAX;i++){ criba[i]=0; }
	for(i=2;i<MAX;i++){
		if(criba[i]==0){
			primos.push_back(i);
			criba[i]+=1;
			for(j=i*2;j<MAX;j+=i){
				criba[j]+=1;
			}
		}
	}
}

void generarMu(){
    for (i=1; i < MAX;   i++){mu[i] = 1;}
    for (i=2; i*i < MAX; i++){
        if (mu[i] == 1){
            for (int j = i; j < MAX; j += i){ mu[j] *= -i; }
            for (int j = i * i; j < MAX; j += i * i){ mu[j] = 0; }
        }
    }
    for (i = 2; i < MAX; i++){
        if (mu[i] == i)
            mu[i] = 1;
        else if (mu[i] == -i)
            mu[i] = -1;
        else if (mu[i] < 0)
            mu[i] = 1;
        else if (mu[i] > 0)
            mu[i] = -1;
    }
}

void especial(){
	f[1]=0;
	for(i=2;i<MAX;i++){
		if(criba[i]==3){
			criba[i] = mu[i] == -1 ? 3 : 0;
		}
		f[i] = criba[i]==3 ? f[i-1]+1 : f[i] = f[i-1];;
	}
}

int main() {
	ios;
	generarPrimos();
    generarMu();
    especial();
	cin>>k;
	while(k--){
		cin>>a>>b;
		cout<<(f[b] - f[a-1])<<endl;
	}
	return 0;
}