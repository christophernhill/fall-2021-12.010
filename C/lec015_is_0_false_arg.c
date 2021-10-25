#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) { 
   if ( argc != 2 ) {
	   printf("Error\n");
	   exit(-1);
   }
   int a;
   int nmatch;
   nmatch = sscanf(argv[1],"%d",&a);
   if ( nmatch != 1 ) {
	   printf("Error\n");
	   exit(-1);
   }
   if ( a ) {
     printf("%d is true\n",a);
   } else {
     printf("%d is false\n",a);
   }
}
