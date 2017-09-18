//"""
//#KYSXD - Problema 3332
//GCD and LCM
//"""
//Status:
//"""

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

long long int elevar_a_p(int a, int p) {
	int temp = p;
    long long int res = 1;
    while (temp != 0) {
    	--temp;
	    res *= a;
    }
    return res;
}

int primes(long long int n) {
	int how_many = 0, max = sqrt(n) + 1;

	if (n%2 == 0) {
		++how_many;

		while (n%2 == 0)
			n /= 2;
	}

	for(long long int i = 3; i <= max && i <= n ; i += 2) {
		if (n%i == 0) {
			++how_many;
			while (n%i == 0)
				n /= i;
		}

	}

	if (n != 1) ++how_many;

	return how_many;
}

int main() {
	int cases, temp;
	long long int N, M, res;

	scanf("%d", &cases);

	for(int i = 0; i < cases; i++) {
		scanf("%lld %lld", &N, &M);
		res = 0;

		if (M%N == 0) {
			if (M == N)
				res = 1;
			else {
				temp = primes(M/N);
				res = elevar_a_p(2, temp - 1);
			}
		}
		printf("%lld\n", res);
	}

	return 0;
}
