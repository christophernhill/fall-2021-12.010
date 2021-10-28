#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
  /* Very common to use pointers instead of multi-dimensional arrays in C         */
  /* in many large C projects this is quite a common approach for regular arrays  */
  double *A;   
  int nx, ny;

  if ( argc != 3 ) {
	  printf("ERROR\n");
	  exit(-1);
  }

  nx = atoi(argv[1]);
  ny = atoi(argv[2]);

  if ( nx < 1 || ny < 1 ) {
	  printf("ERROR\n");
	  exit(-1);
  }

  /*
   Now we use the standard library functions malloc() and sizeof().
   malloc - requests a block of contiguous memory from the operating system
   sizeof - returns the size (in bytes) of a type, so that nx*ny*sizeof(*A) will
            return memory needed for nx*ny doubles (*A). 
  */
  printf("Allocating memory for double array of size %d x %d\n",nx,ny);
  A = (double *)malloc(nx*ny*sizeof(*A));

  for (int j=0;j<ny;++j){
   for (int i=0;i<nx;++i){
	   A[nx*j + i]=i*j;
   }
  }
  for (int j=0;j<ny;++j){
   printf("A[%d,0:%d]=",j,nx-1);
   for (int i=0;i<nx;++i){
    printf("%f ",A[nx*j + i]);
   }
   printf("\n");
  }

  /* free() - releases the memory back to the operating system. */
  free(A);
}
