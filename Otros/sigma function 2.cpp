/**
	UVa 11395 - Sigma Function
	by Rico Tiongson
	Submitted: June 13, 2013
	Accepted 0.016s C++
	O(1) time
*/
#include<cstdio>
#include<cmath>
typedef long long ll;
ll n, sqrtn, bits;
int main(){
	scanf("%lld",&n);
	while( n ){
		sqrtn = sqrt(n);
		bits = log2(n);
		printf( "%lld\n", n - sqrtn + ll(log2(sqrtn)) - bits - ll(sqrt(double(n)/2.)) + ((bits-1LL)>>1) + 1LL ); // bit manipulation to the max
		scanf("%lld",&n);
	}
}
