#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
 
 
void Multiply(double *A, double *B, double *C, const long size) // C = A*B
{

//1 cd ~/Desktop/paralelProgramming-main/
//2 kompilirane g++ -fopenmp -o program matrix.cpp
//3 izpulnqwane time ./program 2048
// tozi dolniq red go pi6a vmesto reda pragma omp parallel
//pragma omp parallel num_threads(4){ 
 
// tozi kod se slaga predi for cikala i samo zaburzva cikli #pragma omp for
//omp_set_num_threads(4);
 
// drugo koeto moje da se polzwa vmesto samo #pragma omp parallel e #pragma omp parallel for schedule(static)
//za suzdavane na paralelen blok
 
 
 omp_set_num_threads(128);
 #pragma omp parallel for
  for (long i=0; i < size; i+=16)
    for (long j=0; j < size; j+=16) {
      C[i*size+j] = 0.0;
       #pragma omp simd
      for (long k=0; k < size; k+=16)
 (C[i*size+j], C[i*size+j+2], C[i*size+j+3], C[i*size+j+4],C[i*size+j+5], C[i*size+j+6], C[i*size+j+7], C[i*size+j+8],
C[i*size+j+9], C[i*size+j+10], C[i*size+j+11], C[i*size+j+12],C[i*size+j+13], C[i*size+j+14], C[i*size+j+15], C[i*size+j+16]) +=
 (A[i*size+k], A[i*size+k+2], A[i*size+k+3], A[i*size+k+4],A[i*size+k+5], A[i*size+k+6], A[i*size+k+7], A[i*size+k+8],
 A[i*size+k+9], A[i*size+k+10], A[i*size+k+11], A[i*size+k+12],A[i*size+k+13], A[i*size+k+14], A[i*size+k+15], A[i*size+k+16])* 
 (B[k*size+j], B[k*size+j+2] ,B[k*size+j+3], B[k*size+j+4],B[k*size+j+5], B[k*size+j+6] ,B[k*size+j+7], B[k*size+j+8],
 B[k*size+j+9], B[k*size+j+10] ,B[k*size+j+11], B[k*size+j+12],B[k*size+j+13], B[k*size+j+14] ,B[k*size+j+15], B[k*size+j+16]);
 }
 
}
 
void PrintMatrix(double *A, const long size)
{
  for (long i = 0; i < size; i++) {
    for (long j = 0; j < size; j++)
      printf("%f ", A[i*size+j]);
    printf("\n");
  }
}
 
void Test()
{
  const long size = 3;
 
  double A[size][size];
  double B[size][size];
  double C[size][size];
 
  A[0][0] = 14.0; A[0][1] = 9.0;  A[0][2] = 3.0;
  A[1][0] = 2.0;  A[1][1] = 11.0; A[1][2] = 15.0;
  A[2][0] = 0.0;  A[2][1] = 12.0; A[2][2] = 17.0;
 
  B[0][0] = 12.0; B[0][1] = 25.0; B[0][2] = 5.0;
  B[1][0] = 9.0;  B[1][1] = 10.0; B[1][2] = 0.0;
  B[2][0] = 8.0;  B[2][1] = 5.0;  B[2][2] = 1.0;
 
  Multiply((double*)&A, (double*)&B, (double*)&C, size);
 
  PrintMatrix((double*)&C, size);
}
 
int main(int argc, char *argv[])
{
  if (argc == 1) {
    Test();
  } else {
    long size = atol(argv[1]);
    printf("size=%ld\n", size);
    double *A = new double[size*size];
    double *B = new double[size*size];
    double *C = new double[size*size];
    Multiply(A, B, C, size);
    PrintMatrix(C, size);
    delete[] C;
    delete[] B;
    delete[] A;
  }
}
 
