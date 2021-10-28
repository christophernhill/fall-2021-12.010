#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
  /* A final important C feature is "typedef" and "struct"                  */
  /* this allows custom types that can gather related information into one  */
  /* variable.                                                              */
  typedef struct {double *arr;
	          int      NX;
		  int      NY;
  } arr2d;

  arr2d A;

  if ( argc != 3 ) {
	  printf("ERROR\n");
	  exit(-1);
  }

  A.NX = atoi(argv[1]);
  A.NY = atoi(argv[2]);

  if ( A.NX < 1 || A.NY < 1 ) {
	  printf("ERROR\n");
	  exit(-1);
  }

  /*
   Now we use the standard library functions malloc() and sizeof().
   malloc - requests a block of contiguous memory from the operating system
   sizeof - returns the size (in bytes) of a type, so that nx*ny*sizeof(*A) will
            return memory needed for nx*ny doubles (*A). 
  */
  printf("Allocating memory for double array of size %d x %d\n",A.NX,A.NY);
  A.arr = (double *)malloc(A.NX*A.NY*sizeof(*A.arr));

  for (int j=0;j<A.NX;++j){
   for (int i=0;i<A.NY;++i){
     A.arr[A.NX*j + i]=i*j;
   }
  }
  for (int j=0;j<A.NY;++j){
    printf("A[%d,0:%d]=",j,A.NX-1);
    for (int i=0;i<A.NX;++i){
     printf("%f ",A.arr[A.NX*j + i]);
    }
    printf("\n");
  }

  /* free() - releases the memory back to the operating system. */
  free(A.arr);
}
