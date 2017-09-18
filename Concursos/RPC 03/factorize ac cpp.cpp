#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#ifndef LOL
typedef __int128 ll;
#else
typedef long long ll;
#endif

ll r[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
vector<ll> toTest;

ll modPow(ll a, ll m, ll n){
	ll ans = 1;

	for (; m; m /= 2){
		if(m % 2)
			ans = (ans * a) % n;
		a = (a * a) % n;
	}
	return ans;
}

bool isPrimeMR(ll n){
	if (n == 2) return true;
	if (n % 2 == 0 || n <= 1) return false;

	ll m;
	int k = 0;
	for(m = n-1; m % 2 == 0; m /= 2) k++;

	for(ll i=0,a=toTest[i]; i<toTest.size(); i++){
		if (a >= n) break;

		ll x = modPow(a, m, n);

		if (x == 1 || x == n-1) continue;

		int j;
		for(j = 0; j < k-1; j++){
			x = (x * x) % n;
			if(x == n-1) break;
		}

		if (j == k - 1) return false;
	}

	return true;
}

ll f(ll &x, ll &A, ll &B, ll &n){
    return x * (x + A) % n + B;
}

ll factor(ll n){
	ll A = 2 + rand() % (n - 2);
	ll B = 2 + rand() % (n - 2);

	ll d, x = 2, y = 2;

	do{
		x = f(x, A, B, n);
		ll t = f(y, A, B, n);
		y = f( t, A, B, n);
		d = __gcd(x >= y ? x - y : y - x, n);
		//cout<<"X: "<<x<<" Y: "<<y<<" D: "<<d<<"\n";
	} while (d == 1);

	return d;
}

void factorize(ll n, vector<ll> &v){
	if (n == 1) return;
	if (isPrimeMR(n)){
		v.push_back(n);
		return;
	}

	ll f;
	do f = factor(n);
	while (f == n);

    printf("-factor: %lld N: %lld\n\n",f,n);

	factorize(f, v);
	factorize(n/f, v);
}

int main(){
	long long int N;
	vector<ll> pr;
	toTest.assign(r, r+12);
	//cout<<"hi"<<endl;
	while(scanf("%lld", &N) && N != -1){
		pr.clear();
		factorize(N, pr);
		sort(pr.begin(), pr.end());
		for (ll i=0,p=pr[i]; i<pr.size(); i++)
			printf("    %lld\n", (long long) p);
		printf("\n");
	}
}

