#include <stdio.h>
int main() {
float a;           /* Floating point number              */
  float *ptr_to_a;   /* Pointer to a floating point number */
 
  a = 7.;            /* Write 7. to memory location associated with a   */
  printf("Value in a == %f\n",a);
 
  ptr_to_a = &a;     /* Get the address of the memory location where    */
                     /* assignments to a get written.                   */
  printf("Memory address of a (in hexadecimal) == %p\n",ptr_to_a);
 
  /* Now use pointer to read value stored at an address                 */
  printf("Value stored at address %p == %f\n",ptr_to_a,*ptr_to_a);
 
  /* Write a new value to an address in memory  */
  *ptr_to_a = 3.;
 
  /* What value does a have now? */
  printf("Value in a == %f\n",a);
 
  /* In C arrays and pointers are the same thing! */
  /* [0] is ptr_to_a + offset of 0*4 bytes        */
  /* [1] is ptr_to_a + offset of 1*4 bytes        */
  /* etc......                                    */
  printf("Value stored at address %p == %f\n",ptr_to_a,ptr_to_a[0]);
 
}
