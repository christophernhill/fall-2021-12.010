/*
  A very basic poly_area in C.
  Illustrates arrays, loops, functions and minimal pointers.
  Does not use structures and types or memory allocation yet.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Pointer and struct approach */
typedef struct {double *narr;
		int   nnodes;
               } n_xy;

/* Function prototypes */
n_xy *read_nodes();
void   get_tri(int, double [2][2], n_xy *);
double calc_da(double [2][2]);
void   check_dir(int, int *, double);

int main(int argc, char *argv[]){
  /* Declare main variables                                     */
  /* nodes_xy -- array to hold points, NMAX maximum number.     */
  /* n_nodes  -- number of nodes entered.                       */
  /* tri_vec  -- array for a single triangle.                   */
  /* area, darea -- accumulated area and area of each addtional */
  /*                increment.                                  */
  int    n_nodes;
  double tri_vec[2][2];
  double area, darea;
  int    sign_da;

  n_xy *nodes_xy;

  /* Start message */
  printf("=== Computing polygon area ==\n");

  /* Get node list */
  nodes_xy = read_nodes();

  /* Check we have enough nodes */
  if ( nodes_xy->nnodes < 3 ) {
    printf("ERROR: Not enough nodes entered\n");
    exit(-1);
  } else {
    printf("%d nodes entered\n",nodes_xy->nnodes);
  }

  for (int i=2;i<nodes_xy->nnodes;i=i+1) {
    /* Form a triangle */
    get_tri(i,tri_vec,nodes_xy);
    /* Calculate triangle area increment */
    darea=calc_da(tri_vec);
    /* See if we are moving in consistent direction */
    check_dir(i,&sign_da,darea);
    /* Accumulate area */
    area=area+darea;
  }

  printf("Area = %lf\n",fabs(area));
}

n_xy *read_nodes(){
	/* Allocate memory in blocks of nblk */
	int nblk=100;
	n_xy *nodes_xy_def;
	double *arr_def;

	/* Set initial block */
	arr_def=(double *)malloc(sizeof(double)*nblk*2);
        nodes_xy_def=(n_xy *)malloc(sizeof(n_xy));
        nodes_xy_def->narr=arr_def;

	/* Read nodes */
	double X, Y;
	int nread;
	int nnodes=0;
	int ioff;
	while (  ( nread=scanf("%lf %lf\n",&X,&Y) ) != -1 ) {
         if ( nread != 2 ) {
	      printf("Invalid line format entered.\n");
	      exit(-1);
         } else {
           ioff=2*nnodes;
	   nodes_xy_def->narr[ioff+0]=X;
	   nodes_xy_def->narr[ioff+1]=Y;
           nnodes=nnodes+1;
	   if ( nnodes%nblk == 0 ) {
            /* We have reached a multiple of nblk, so allocate some more memory */
            int newcount=nnodes+nblk;
	    nodes_xy_def->narr=(double *)realloc(nodes_xy_def->narr,sizeof(double)*newcount*2);
	   }
         }
	}

	nodes_xy_def->nnodes=nnodes;
	return nodes_xy_def;
}

void get_tri(int i, double t_vec[2][2], n_xy *nodes_xy){
	int ioff=2*i;
	int im1off=2*(i-1);
	t_vec[0][0]=nodes_xy->narr[im1off  ]-nodes_xy->narr[0];
	t_vec[1][0]=nodes_xy->narr[im1off+1]-nodes_xy->narr[1];
	t_vec[0][1]=nodes_xy->narr[ioff    ]-nodes_xy->narr[0];
	t_vec[1][1]=nodes_xy->narr[ioff+1  ]-nodes_xy->narr[1];
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
