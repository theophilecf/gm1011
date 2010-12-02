#include <stdio.h>

#include "bs.h"

void BS_eval ( double *S, double **P, double x, double *t,
               int k, int n, int s) {
	int i, j;

	for (i = 0; i < s; i++) {
		S[i] = 0;
		for (j = 0; j <= n-1; j++)
			S[i] += P[j][i] * Bij (x, t, j, k);
	}
}

double wij (double x, double *t, int i, int j) {
	if (t[i] < t[i+j])
		return (x - t[i])/(t[i+j] - t[i]);
	else
		return 0;
}

double Bi0 (double x, double *t, int i) {
	if (t[i] <= x && x < t[i+1])
		return 1;
	else
		return 0;
}

double Bij (double x, double *t, int i, int j) {
	if (j == 0)
		return Bi0 (x, t, i);
	else
		return wij (x, t, i, j)        * Bij (x, t, i, j-1) +
		       (1 - wij (x, t, i+1,j)) * Bij (x, t, i+1,j-1);
}
