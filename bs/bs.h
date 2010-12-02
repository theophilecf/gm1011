#ifndef BS_H
#define BS_H

/* Evaluate S(x) = P_i * B_{0,k}(x) + ... + a_{n-1} * B_{n-1,k}(x) 
 *
 * S in R^s, P_i in R^s
 * t in R^{n+k} (nodes)
 */
void BS_eval ( double *S, double **P, double x, double *t,
               int k, int n, int s);

double wij (double x, double *t, int i, int j);

double Bi0 (double x, double *t, int i);

double Bij (double x, double *t, int i, int j);

#endif
