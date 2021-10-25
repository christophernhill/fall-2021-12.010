#include <stdio.h>
int below_epsilon( double );
int main(int argc, char *argv){
	double x = 100.;
	if ( below_epsilon(x) ) {
         printf("1-x=1, for x =%f\n",x);
	} else {
         printf("1-x=1-x, for x =%f\n",x);
	}
}
