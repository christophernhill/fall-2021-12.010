/*
  A very basic poly_area in C.
  Illustrates arrays, loops, functions and minimal pointers.
  Does not use structures and types or memory allocation yet.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int NMAX=1000;

/* Function prototypes */
int    read_nodes( double [2][NMAX], int );
void   get_tri(int, double [2][2], double [2][NMAX], int);
double calc_da(double [2][2]);
void   check_dir(int, int *, double);

int main(int argc, char *argv[]){
  /* Declare main variables                                     */
  /* nodes_xy -- array to hold points, NMAX maximum number.     */
  /* n_nodes  -- number of nodes entered.                       */
  /* tri_vec  -- array for a single triangle.                   */
  /* area, darea -- accumulated area and area of each addtional */
  /*                increment.                                  */
  double nodes_xy[2][NMAX];
  int    n_nodes;
  double tri_vec[2][2];
  double area, darea;
  int    sign_da;

  /* Start message */
  printf("=== Computing polygon area ==\n");

  /* Get node list */
  n_nodes=read_nodes(nodes_xy, NMAX);

  /* Check we have enough nodes */
  if ( n_nodes < 3 ) {
    printf("ERROR: Not enough nodes entered\n");
    exit(-1);
  }

  for (int i=2;i<n_nodes;i=i+1) {
    /* Form a triangle */
    get_tri(i,tri_vec,nodes_xy,n_nodes);
    /* Calculate triangle area increment */
    darea=calc_da(tri_vec);
    /* See if we are moving in consistent direction */
    check_dir(i,&sign_da,darea);
    /* Accumulate area */
    area=area+darea;
  }

  printf("Area = %lf\n",fabs(area));
}

int read_nodes(double n_xy[2][NMAX], int nmax){

    double X,Y,nread;
    int n_nodes=0;
    printf("Enter space-separated pairs of coordinates of the nodes, one pair per line.\n");

    while (  ( nread=scanf("%lf %lf\n",&X,&Y) ) != -1 ) {
      if ( nread != 2 ) {
	      printf("Invalid line format entered.\n");
	      exit(-1);
      } else {
	n_xy[0][n_nodes]=X;
	n_xy[1][n_nodes]=Y;
        n_nodes=n_nodes+1;
      }
      if ( n_nodes == nmax ) {
	      printf("Too many nodes.\n");
	      exit(-1);
      }
    }
    printf("Polygon has %d nodes.\n",n_nodes);
    return n_nodes;
}

void get_tri(int i, double t_vec[2][2], double n_xy[2][NMAX], int n_n){
	t_vec[0][0]=n_xy[0][i-1]-n_xy[0][0];  /* Poly start to point 1 */
	t_vec[1][0]=n_xy[1][i-1]-n_xy[1][0];
	t_vec[0][1]=n_xy[0][i  ]-n_xy[0][0];  /* Poly start to point 2 */
	t_vec[1][1]=n_xy[1][i  ]-n_xy[1][0];
}

double calc_da(double t_vec[2][2]){
	double da=0.;
	da = ( t_vec[0][0]*t_vec[1][1] -
	       t_vec[1][0]*t_vec[0][1] )*0.5;
	return da;
}

void check_dir(int inum,int *s, double da){
	if ( inum == 2 ) {
          if ( da < 0. ) {
           *s = -1;
          } 
	  else {
           *s = +1;
	  }
	} 
	else 
	{
	  if ( *s*da < 0. ) {
           printf("ERROR: Point direction has changed at node %d.\n",inum+1);
	   exit(-1);
	  }
	}
}
