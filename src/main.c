/* Ralph Gabriel R. Bautista S15 */
/* Ghee Kaye S. Lopez S15 */

#include <stdio.h>
#include <stdlib.h>

// Declare the external assembly function
extern void daxpy(int n, double A, double *X, double *Y, double *Z);

int main() {
    int n, i;
    double A;
    double *X, *Y, *Z;

    // Input for vector size and scalar
    printf("Enter vector size (n): ");
    scanf("%d", &n);
    printf("Enter scalar value (A): ");
    scanf("%lf", &A);

    // Allocate memory for vectors
    X = (double *)malloc(n * sizeof(double));
    Y = (double *)malloc(n * sizeof(double));
    Z = (double *)malloc(n * sizeof(double));

    if (!X || !Y || !Z) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    // Input values for vector X
    printf("\nEnter %d elements for vector X:\n", n);
    for (i = 0; i < n; i++) {
        printf("X[%d] = ", i);
        scanf("%lf", &X[i]);
    }

    // Input values for vector Y
    printf("\nEnter %d elements for vector Y:\n", n);
    for (i = 0; i < n; i++) {
        printf("Y[%d] = ", i);
        scanf("%lf", &Y[i]);
    }

    // Display input vectors (debuggin line only)
    printf("\nInput Vectors (First 10 Elements):\n");
    printf("X: ");
    for (i = 0; i < (n < 10 ? n : 10); i++) {
        printf("%.2f ", X[i]);
    }
    printf("\nY: ");
    for (i = 0; i < (n < 10 ? n : 10); i++) {
        printf("%.2f ", Y[i]);
    }
    printf("\n");

    // Call assembly function
    printf("Calling daxpy function...\n");
    daxpy(n, A, X, Y, Z);
    printf("Returned from daxpy function...\n");

    // Display result (first 10 elements)
    printf("\nResult (First 10 Elements):\n");
    for (i = 0; i < (n < 10 ? n : 10); i++) {
        printf("Z[%d] = %.2f\n", i, Z[i]);
    }

    // Free allocated memory
    free(X);
    free(Y);
    free(Z);

    return 0;
}
