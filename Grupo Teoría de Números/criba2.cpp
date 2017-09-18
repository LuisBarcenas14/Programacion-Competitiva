#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
#define endl '\n'

const int MAX = 1000010;

bool criba[MAX];
vi primos;

void sieve(){
	ll i,j;
	for(i=2; i<MAX; i++)if(!criba[i]){
		primos.push_back(i);
		for(j=i*i; j<MAX; j+=i)
			criba[j]=true;
	}
	/*for(int i=0; i<10; i++)
		cout<<primos[i]<<" ";//*/
}

bool isPrimeF(int n){

	for(int i=0; i<(int)primos.size(); i++){
		if(n==primos[i]) return true;
	}
	return false;
}

bool isPrime(ll n){
	ll j=0, p=primos[j];
	while(p*p<=n){
		if(n%p==0) return false;
		p=primos[++j];
	}
	return true;
}

void primeFactors(ll n){
	ll j=0, p=primos[j];
	while(p*p<=n){
		while(n%p==0){ 
			cout<<p<<" ";
			n/=p;
		}
		p=primos[++j];
	}
	if(n!=1) cout<<n<<" ";
	cout<<endl;
}

int numDiv(ll n){
	ll j=0; p=primos[j],e,res=1;
	while(p*p<=n){
		e=0;
		while(n%p==0){
			e++;
			n/=p;
		}
		e++;
		res*=e;
		p=primos[++j];
	}
}

int main(){
	sieve();
	int n;
	while(cin>>n && n!=0){
		primeFactors(n);
	}
	return 0;
}

