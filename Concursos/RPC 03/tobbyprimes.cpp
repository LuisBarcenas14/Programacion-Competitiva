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

vector<ll> toTest = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

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

	for(auto a: toTest){
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

std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}

ll factor(ll n){
	ll A = 2 + rand() % (n - 2);
	ll B = 2 + rand() % (n - 2);

	auto f = [&](ll x){ return x * (x + A) % n + B; };
	ll d, x = 2, y = 2;

	do{
        x = f(x);
		y = f(f(y));
		d = __gcd(x >= y ? x - y : y - x, n);
		//cout<<"4. X: "<<x<<" Y: "<<y<<" D: "<<d<<" A: "<<A<<" B: "<<B<<"\n";

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

	factorize(f, v);
	factorize(n/f, v);
}

int main(){
    //freopen("inPrimes","in",stdin);
    //freopen("outPrimes","out",stdout);
	long long int N,t;
	int it;
	vector<ll> pr;
	scanf("%lld", &t);
	while(t--){
        scanf("%lld", &N);
		pr.clear();
		factorize(N, pr);
		sort(pr.begin(), pr.end());
		for(it=0;it<(int)pr.size()-1; it++){
            printf("%lld ", (long long) pr[it]);
		}

		printf("%lld\n",(long long) pr[it]);
	}
}
