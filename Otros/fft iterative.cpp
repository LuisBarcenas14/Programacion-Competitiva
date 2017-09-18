#include <iostream>
#include <cstdio>
#include <cmath>
#include <complex>
using namespace std;
#define endl '\n'
#define PI M_PI
//const int M = (1<<3);
int M;
typedef long double ld;

complex<ld> getPrimitiveRootOfUnity(int gen) {
    return complex<ld>(cos(2*PI/gen), sin(2*PI/(double)gen));
}
class Polynomial {
private:
    int sz;
public:
    complex<ld> *f;
    Polynomial(int sz) {
        this->sz = sz;
        this->f = new complex<ld>[this->sz];
        for(int i = 0; i < this->sz; i++) this->f[i] = complex<ld>(0.0,0.0);
    }
};
inline Polynomial FFT(Polynomial A, int m, complex<ld> w)
{
    if (m==1) return A;

    Polynomial A_even(m/2);
    Polynomial A_odd(m/2);
    for(int i = 0; i < m; i+=2) {
        A_even.f[i/2] = A.f[i];
        A_odd.f[i/2] = A.f[i+1];
    }
    Polynomial F_even = FFT(A_even, m/2, w*w);    //w^2 is a primitive m/2-th root of unity
    Polynomial F_odd = FFT(A_odd, m/2, w*w);
    Polynomial F(m);
    complex<ld> x(1.0,0.0);
    for (int j=0; j < m/2; ++j) {
      F.f[j] = F_even.f[j] + x*F_odd.f[j];
      F.f[j+m/2] = F_even.f[j] - x*F_odd.f[j];
      x = x * w;
    }
    return F;
}

void imprimir(Polynomial C,int n, string s){
    cout<<s<<"-------------------------"<<endl;
    if(n==0){ return; }
    cout<<C.f[0].real();
    for(int i = 1; i < n; i++) cout<<" + "<<C.f[i].real()<<"x^"<<i;
    cout<<endl;
}

int main() {
    freopen("in","r",stdin);
    int n;
    cin>>n;
    M=1;
    while(M<n){
        M<<=1;
    }
    M<<=1;
    M=8;
    Polynomial A(M), B(M);
    cout<<"inicio"<<endl;
    imprimir(A,M/2,"init A");
    imprimir(B,M/2,"init B");
    // enter polynomial A and B both with M/2 degree
    //enterPolynomial_A;
    ld element;
    for(int i=0;i<n;i++){
        cin>>element;
        A.f[i]=element,0.0;
    }
    imprimir(A,M/2,"A");
    //enterPolynomial_B;
    for(int i=0;i<n;i++){
        cin>>element;
        B.f[i]=element,0.0;
    }
    imprimir(B,M/2,"B");
    //end input
    complex<ld> w = getPrimitiveRootOfUnity(M);
    Polynomial F_A = FFT(A, M, w);
    Polynomial F_B = FFT(B, M, w);
    Polynomial F_C(M);
    imprimir(F_A,M,"F_A");
    for(int i = 0; i < M; i++) F_C.f[i] = F_A.f[i] * F_B.f[i];
    // w_ = w^{-1}
    complex<ld> w_(1,0);
    for(int i = 0; i < M-1; i++) w_ *= w;
    // 2 last statement to compute result polynomial, result going to be located in C
    Polynomial C = FFT(F_C, M, w_);
    imprimir(C,M,"C");
    for(int i = 0; i < M; i++) C.f[i] *= (ld)1.0/M;
    imprimir(C,2*n-1,"C");
	return 0;
}
