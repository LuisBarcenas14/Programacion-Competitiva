#define _USE_MATH_DEFINES // para la constante M_PI

#include <stdlib.h>
#include <cstdlib>          // std::malloc
#include <iostream>         // std::cout
#include <math.h>           // M_PI
#include <stdio.h>          // print, sprintf

using namespace std;


// obtener la constante PI desde math.h
#define PI M_PI

// Definimos estructura de numeros complejos
typedef struct {
   double r; // parte real
   double i; // parte imaginaria
} complex;


void fft_recursivo(complex* a, complex* y, int n, int inv);

void multiplicar_polinomios(complex* a, complex* b, int n);

// multiplicar dos numeros complejos
complex complex_mul(complex a, complex b);

// sumar dos numeros complejos
complex complex_add(complex a, complex b);

// restar dos numeros complejos
complex complex_sub(complex a, complex b);


// Algoritmo FFT recursivo
// Cormen pp 911, tercera edicion
void fft_recursivo(complex* a, complex* y, int n, int inv) {
   complex w, wn, twiddle;
   complex* a0;
   complex* a1;
   complex* y0;
   complex* y1;
   int i, k;

   // Caso base
   if (n == 1) {
      y[0] = a[0];
      return;
   }
   // Calcular raices exp(2*PI*i/n)
   if ( inv ){
      wn.r = cos(-2 * PI / (double)n);
      wn.i = sin(-2 * PI / (double)n);
   }else {
      wn.r = cos(2 * PI / (double)n);
      wn.i = sin(2 * PI / (double)n);
   }

   w.r = 1.0;
   w.i = 0.0;

   // Separar memoria para coeficientes pares/impares a FFT correspondientes
   a0 = (complex*)std::malloc((n / 2) * sizeof(complex));
   a1 = (complex*)std::malloc((n / 2) * sizeof(complex));
   y0 = (complex*)std::malloc((n / 2) * sizeof(complex));
   y1 = (complex*)std::malloc((n / 2) * sizeof(complex));

   // Extraer coeficientes pares e impares
   for (i = 0; i < (n / 2); i++) {
      a0[i] = a[2 * i];
      a1[i] = a[2 * i + 1];
   }

   // Calcular 2 FFTs de tamano n/2
   fft_recursivo(a0, y0, n / 2, inv);
   fft_recursivo(a1, y1, n / 2, inv);

   // Combinar resultados de las FFTs/2
   for (k = 0; k < (n / 2); k++) {
      twiddle      = complex_mul(w, y1[k]);
      y[k]         = complex_add(y0[k], twiddle);
      y[k + n / 2] = complex_sub(y0[k], twiddle);

      // printf("w = (%.4f, %.4f), y[%d] = (%.4f, %.4f), y[%d] = (%.4f, %.4f)", w.r, w.i, k, y[k].r, y[k].i, k + n / 2, y[k + n / 2].r, y[k + n / 2].i );
      w = complex_mul(w, wn);
   }

   std::free(a0);
   std::free(a1);
   std::free(y0);
   std::free(y1);

   return;
}

// n -> hasta donde vamos a imprimir
void imprimir_polinomio_coeff( complex* p, int n ) {
   for ( unsigned int k = 0; k < n; k++) {
      std::cout << p[k].r;

      // no imprimir x^0
      if ( k != 0 ) {
         std::cout << "x^" << k;
      }

      // No imprimir ultimo guion
      if ( k != n - 1 ) {
         std::cout << " + ";
      }
   }
   std::cout << std::endl;
}

// Maxima potencia de 2 a probar 20
// 2^20
#define MAX_N        (1<<20)

int main(int argc, char* argv[] ) {
   freopen("in","r",stdin);
   // Numero de coeficientes del polinomio
   int numeroCoef;

   // Polinomios
   complex* a;
   complex* b;

  // Leer tamano del array de coeficientes
  scanf("%d", &numeroCoef);

  // Variables solo para imprimir resultados del polinomio
  int numeroCoefA = numeroCoef;
  int numeroCoefB = numeroCoef;

  int siguientePotenciaDe2;
  siguientePotenciaDe2 = 1;
  while ( siguientePotenciaDe2 < numeroCoef ){
     siguientePotenciaDe2 <<= 1;
  }

  // Separar espacio para los polinomios
  a = (complex*)malloc( 2 * siguientePotenciaDe2 * sizeof(complex) );
  b = (complex*)malloc( 2 * siguientePotenciaDe2 * sizeof(complex) );

  // Leer coeficientes de a
  int coeff;
  for (int i = 0; i < numeroCoef; i++) {
     scanf("%d", &coeff);
     a[i].r  = (double)coeff;
     // std::cout << "a[" << i << "].r: " << a[i].r << std::endl;
     a[i].i  = 0.0;
  }

  // Leer Coeficientes de b
  for (int i = 0; i < numeroCoef; i++) {
     scanf("%d", &coeff);
     b[i].r = (double)coeff;
     b[i].i = 0.0;
  }

  for (int i = numeroCoef; i < (2 * siguientePotenciaDe2); i++) {
     a[i].r = 0.0; a[i].i = 0.0;
     b[i].r = 0.0; b[i].i = 0.0;
  }

  numeroCoef = siguientePotenciaDe2;

  multiplicar_polinomios( a, b, 2 * numeroCoef );
  int numeroCoefProducto = numeroCoefA + numeroCoefB - 1;
  // Imprimir Polinomio
  std::cout << "P(x)= ";
  imprimir_polinomio_coeff( a, numeroCoefProducto );
  std::free(a);
  std::free(b);

   return 0;
}

// Definicion de multiplicacion de polinomios
void multiplicar_polinomios(complex* a, complex* b, int n) {
   complex* ya;
   complex* yb;
   int j;

   // Separar memoria para los resultados de la FFT
   ya = (complex*)std::malloc(n * sizeof(complex));
   yb = (complex*)std::malloc(n * sizeof(complex));

   // DFT de A y B
   fft_recursivo(a, ya, n, 0);
   fft_recursivo(b, yb, n, 0);

   // Multiplicación por puntos
   for (j = 0; j < n; j++){
      ya[j] = complex_mul(ya[j], yb[j]);
   }

   // Inversa DFT ( intercambiadas vectores de entrada y de salida)
   fft_recursivo(ya, a, n, 1);

   // Dividir parte real por n
   for (j = 0; j < (n - 1); j++)
      a[j].r = a[j].r / n;

   std::free(ya);
   std::free(yb);
}

// Definicion de operacion con complejos
// Multiplicacion
complex complex_mul(complex a, complex b) {
   complex ans;

   ans.r = a.r * b.r - a.i * b.i;
   ans.i = a.r * b.i + a.i * b.r;

   return ans;
}

// Suma
complex complex_add(complex a, complex b) {
   complex ans;

   ans.r = a.r + b.r;
   ans.i = a.i + b.i;

   return ans;
}

// Resta
complex complex_sub(complex a, complex b) {
   complex ans;

   ans.r = a.r - b.r;
   ans.i = a.i - b.i;

   return ans;
}

