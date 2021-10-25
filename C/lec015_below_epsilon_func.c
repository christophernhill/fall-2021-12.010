int below_epsilon(double x ){
	int is_below_eps=0;  // 0 is treated as false in C
	                     // non-zero is treated as true.
        double a, b;
	a = 1.;
	b = 1. - x;
	is_below_eps = (a == b);
        return is_below_eps;
}
