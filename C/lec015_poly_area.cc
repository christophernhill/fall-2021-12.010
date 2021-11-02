/*
  A poly_area in C++.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* First lets define a polygon point "class". */
class ppoint{
	public:
          ppoint(){};
	  ppoint(double, double);
	  ~ppoint(){};
	  ppoint operator=(ppoint);
	  ppoint operator+(ppoint);
	  ppoint operator-(ppoint);
	  void print();
        private:
	  double X;
	  double Y;
	  friend class poly;
};
ppoint ppoint::operator= (ppoint pp2)
{
  X = pp2.X; Y = pp2.Y;
  return( *this );
}
ppoint ppoint::operator+ (ppoint pp2)
{ ppoint temp;
  temp.X = X + pp2.X; temp.Y = Y + pp2.Y;
  return(temp);
}
ppoint ppoint::operator- (ppoint pp2)
{ ppoint temp;
  temp.X = X - pp2.X; temp.Y = Y - pp2.Y;
  return(temp);
}
ppoint::ppoint(double xi, double yi)
{ this->X = xi;
  this->Y = yi;
}
void ppoint::print()
{ printf("(%f",X);
  printf(",%f)\n",Y);
}

class poly{
	public:
	 poly();
	 void append(ppoint);
	 void print();
	 double area();
	 ppoint *parr;
	 int    ncur;
	 int    nnodes_max;
	private:
         static const int nblk=10;
};
poly::poly(){
      this->parr = new ppoint[this->nblk];
      this->nnodes_max = this->nblk;
      this->ncur=0;
}
void poly::append(ppoint pa){
	int nc=this->ncur;
	int nm=this->nnodes_max;
	if ( nc == nm ) {
          int nmnew=nm+this->nblk;
	  ppoint *parrnew = new ppoint[nmnew];
	  for (int i=0;i<nc;++i){
           parrnew[i]=this->parr[i];
	  }
	  delete this->parr;
	  this->parr=parrnew;
	}
	this->parr[nc]=pa;
	++this->ncur;
}
void poly::print()
{    for (int i=0;i<this->ncur;++i){
	this->parr[i].print();
     }
}
double poly::area()
{      double pa=0.;
       double tvec[2][2];
       ppoint v1, v2;
       for (int i=2;i<this->ncur;++i){
        v1=this->parr[i-1]-this->parr[0];
        v2=this->parr[i  ]-this->parr[0];
	pa=pa+(v1.X*v2.Y-v1.Y*v2.X)*0.5;
       }
       return pa;
}

int main(int argc, char *argv[]){
	poly poly1;
	poly1.append( ppoint(0.,0.) );
	poly1.append( ppoint(2.,0.) );
	poly1.append( ppoint(2.,2.) );
	poly1.append( ppoint(0.,2.) );
	poly1.append( ppoint(0.,0.) );
	poly1.print();
	printf("Poly area = %f\n",poly1.area());
}
