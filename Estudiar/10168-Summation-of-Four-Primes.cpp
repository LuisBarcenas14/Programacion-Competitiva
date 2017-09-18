#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <bitset>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0)
#define TAM 2600000

//tiempo 0.040
typedef long long int lli;
using namespace std;

int primos[664580], c, r[4];
bitset<TAM+10> criba;

bool generaCriba(){
	lli i, j;
	criba.set();
	criba[0]=criba[1]=false;
	c=0;
	for(i=2;i<=TAM;i++){
		if(criba[i]){
			for(j=i*i;j<=TAM;j+=i){
				criba[j]=false;
			}
			primos[c++]=i;
		}
	}
}
bool esPrimo(int n){
	int i, p=2;;
	for(i=1;p*p<=n;i++){
		if(n%p==0)return false;
		p=primos[i];
	}
	return true;
}
bool backtrack(int p, int n){
	if(p==3){
		if(n<TAM){
			if(criba[n]){
				r[p]=n;
				return true;
			}
			return false;
		}
		if(esPrimo(n)){
			r[p]=n;
			return true;
		}else return false;
	}
	int i;
	if(n>primos[c-1]){
		for(i=c-1;i>=c-1000;i--){ //espero que con los primeros 1000 sea suficiente
			if(backtrack(p+1, n-primos[i])){
				r[p]=primos[i];
				return true;
			}
		}
		return false;
	}
	for(i=0;i<c &&n-primos[i]>0;i++){
		if(backtrack(p+1, n-primos[i])){
			r[p]=primos[i];
			return true;
		}
	}
	return false;
}
int main(){
	FASTIO;
	int n,i;
	generaCriba();
	//for(i=0;i<100;i++)
		//cout<<primos[i]<<" ";
	//cout<<"termina "<<c<<"  ultimo "<<primos[c-1]<<"\n";
	while(cin>>n){
		i=0;
		if(n%2){
			n-=2;
			r[i++]=2;
		}
		if(backtrack(i, n)){
			cout<<r[0];
			for(i=1;i<4;i++)
				cout<<" "<<r[i];
		}else cout<<"Impossible.";
		cout<<"\n";
	}
	return 0;
}