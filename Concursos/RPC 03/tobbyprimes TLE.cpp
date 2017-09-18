#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
#define MAX 1000001
#define LIM 1000000000000
#define endl '\n'

vll factors;
ll i,j;
bool criba[MAX];
vector<int> primos;

void sieve(){
    for(i=2;i<MAX;i++)if(!criba[i]){
        primos.push_back(i);
        for(j=i*i;j<MAX;j+=i)
            criba[j]=true;
    }
}

// Utility function to do modular exponentiation.
ll power(ll x, unsigned long long int y, ll p){
    ll res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
                // equal to p
    while (y > 0){
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

// This function is called for all k trials. It returns
// false if n is composite and returns false if n is
// probably prime.
// d is an odd number such that  d*2<sup>r</sup> = n-1
// for some r >= 1
bool miillerTest(ll d, ll n){
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    ll a = 2 + rand() % (n - 4);

    // Compute a^d % n
    ll x = power(a, d, n);

    if (x == 1  || x == n-1)
       return true;

    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n-1){
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false;
        if (x == n-1)    return true;
    }

    // Return composite
    return false;
}

// It returns false if n is composite and returns true if n
// is probably prime.  k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.
bool isPrime(ll n, int k){
    // Corner cases
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;

    // Find r such that n = 2^d * r + 1 for some r >= 1
    ll d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    // Iterate given nber of 'k' times
    for (int i = 0; i < k; i++)
         if (miillerTest(d, n) == false)
              return false;

    return true;
}

/* Function to calculate (base^exponent)%modulus */
long long int modular_pow(long long int base, int exponent,
                          long long int modulus)
{
    /* initialize result */
    long long int result = 1;

    while (exponent > 0)
    {
        /* if y is odd, multiply base with result */
        if (exponent & 1)
            result = (result * base) % modulus;

        /* exponent = exponent/2 */
        exponent = exponent >> 1;

        /* base = base * base */
        base = (base * base) % modulus;
    }
    return result;
}

ll gcd(ll a, ll b){
    return b==0 ? a : gcd(b, a%b);
}

/* method to return prime divisor for n */
long long int PollardRho(long long int n){
    /* initialize random seed */
    //srand (time(NULL));
    /* no prime divisor for 1 */
    if (n==1) return n;

    /* even number means one of the divisors is 2 */
    if (n % 2 == 0) return 2;

    /* we will pick from the range [2, N) */
    long long int x = (random()%(n-2))+2;
    long long int y = x;

    /* the constant in f(x).
     * Algorithm can be re-run with a different c
     * if it throws failure for a composite. */
    long long int c = (random()%(n-1))+1;

    /* Initialize candidate divisor (or result) */
    long long int d = 1;

    /* until the prime factor isn't obtained.
       If n is prime, return n */
    while (d==1){
        /* Tortoise Move: x(i+1) = f(x(i)) */
        x = (modular_pow(x, 2, n) + c + n)%n;

        /* Hare Move: y(i+1) = f(f(y(i))) */
        y = (modular_pow(y, 2, n) + c + n)%n;
        y = (modular_pow(y, 2, n) + c + n)%n;

        /* check gcd of |x-y| and n */
        d = gcd(abs(x-y), n);

        /* retry if the algorithm fails to find prime factor
         * with chosen x and c */
        if (d==n) return PollardRho(n);
    }

    return d;
}

void factorizar(ll &n){
    ll j=0,p=primos[j];
    while(p*p<=n && p){
        if(n%p==0){
            while(n%p==0){ n/=p; factors.push_back(p); }
        }
        p=primos[++j];
    }
}

void factorizarR(ll &n, ll L, ll R=MAX){
    ll j=L,p=primos[j];
    while(p*p<=n && p && j<=R){
        if(n%p==0){
            while(n%p==0){ n/=p; factors.push_back(p); }
        }
        p=primos[++j];
    }
}

int main(){
    //freopen("inJ","r",stdin);
    //ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    int t,k=4;
    ll n, div, fin;
    ll t1=1000000014000000049;
    cout<<t1<<endl;
    cout<<PollardRho(t1)<<endl;
    scanf("%d",&t);
    //cin>>t;
    while(t--){
        scanf("%lld",&n);
        //cout<<PollardRho(n)<<endl;
        if(n<=LIM){
            factorizar(n);
        }else{
            factorizarR(n,0,100);
            cout<<n<<" es primo: "<<isPrime(n, 4)<<endl;
            while(!isPrime(n, k) && n!=1){
                cout<<"?"<<endl;
                if(n<=LIM){
                    factorizarR(n, 101);
                }else{
                    div = PollardRho(n);
                    while(n%div==0){
                        n/=div;
                        printf("%lld ",div);
                        //factors.push_back(div);
                    }
                }
            }
        }
        if(n!=1){ factors.push_back(n); }
        sort(factors.begin(), factors.end());
        for(int i=0; i<factors.size(); i++){
            printf("%lld ",factors[i]);
            //cout<<factors[i]<<" ";
        }
        printf("\n");
        factors.clear();
    }
    return 0;
}

