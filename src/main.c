#include <stdio.h>
#include <stdlib.h>

extern void daxpy(double *X, double *Y, double *Z, int n, double A);

int main() {
    int n, i;
    double *X, *Y, *Z, A;

    // Input for vector size and scalar
    printf("Enter vector size (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for vector size.\n");
        return -1;
    }

    // Allocate memory for vectors
    X = (double *)malloc(n * sizeof(double));
    Y = (double *)malloc(n * sizeof(double));
    Z = (double *)malloc(n * sizeof(double));

    if (!X || !Y || !Z) {
        printf("Memory allocation failed.\n");
        free(X);
        free(Y);
        free(Z);
        return -1;
    }

    // Input values for vector X
    printf("\nEnter %d elements for vector X:\n", n);
    for (i = 0; i < n; i++) {
        printf("X[%d] = ", i);
        if (scanf("%lf", &X[i]) != 1) {
            printf("Invalid input for X[%d].\n", i);
            free(X);
            free(Y);
            free(Z);
            return -1;
        }
    }

    // Input values for vector Y
    printf("\nEnter %d elements for vector Y:\n", n);
    for (i = 0; i < n; i++) {
        printf("Y[%d] = ", i);
        if (scanf("%lf", &Y[i]) != 1) {
            printf("Invalid input for Y[%d].\n", i);
            free(X);
            free(Y);
            free(Z);
            return -1;
        }
    }
    
    printf("\n");

    printf("Enter scalar value (A): ");
    if (scanf("%lf", &A) != 1) {
        printf("Invalid input for scalar value.\n");
        return -1;
    }

    daxpy(X, Y, Z, n, A);

    // Display result (first 10 elements)
    printf("\nResult (First 10 Elements):\n");
    for (i = 0; i < (n < 10 ? n : 10); i++) {
        printf("Z[%d] = %.2lf\n", i, Z[i]);
    }

    // Free allocated memory
    free(X);
    free(Y);
    free(Z);

    return 0;
}
