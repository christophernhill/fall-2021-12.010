#include <stdio.h>
int main(int argc, char *argv[]) { 
   for (int a=-50;a<50;a=a+10) {
     if ( a ) {
       printf("%d is true\n",a);
     } else {
       printf("%d is false\n",a);
     }
   }
}
