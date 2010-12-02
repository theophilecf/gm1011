#include <stdio.h>

#include "bs.h"

int main (void)
{
	double t[10] = {0., 0., 0., 0., 1. ,1., 1., 1.};
	double *P[4];
	double P1[3] = {0., 0., 0.},
	       P2[3] = {1., 1., 1.},
	       P3[3] = {3., 1., 2.},
	       P4[3] = {5., 0., 0.};
	
	int i, k = 3;

	double x, y[3];

	int N = 100;

	P[0] = P1;
	P[1] = P2;
	P[2] = P3;
	P[3] = P4;

	for (i = 0; i <= N; i++) {
		x = (double) i / N;
		BS_eval (y, P, x, t, k, 4, 3);
		printf ("%lf %lf %lf\n", y[0], y[1], y[2]);
	}

	return 0;
}
