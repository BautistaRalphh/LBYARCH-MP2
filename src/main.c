/* Ralph Gabriel R. Bautista S15 */
/* Ghee Kaye S. Lopez S15 */

#include <stdio.h>
#include <stdlib.h>

extern double daxpy (int n, double A, double *X, double *Y, double *Z)

int main () {
    int n;
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

    //Validation check
    if (!X || !Y || !Z) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    // Input values for the vectors
    printf("\nEnter %d elements for vector X:\n", n);
    for (int i = 0; i < n; i++) {
        printf("X[%d] = ", i);
        scanf("%lf", &X[i]);
    }

    printf("\nEnter %d elements for vector Y:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Y[%d] = ", i);
        scanf("%lf", &Y[i]);
    }

    // Display input vectors (debugging lines)
    printf("\nInput Vectors (First 10 Elements):\n");
    printf("X: ");
    for (int i = 0; i < (n < 10 ? n : 10); i++) printf("%.2f ", X[i]);
    printf("\nY: ");
    for (int i = 0; i < (n < 10 ? n : 10); i++) printf("%.2f ", Y[i]);
    printf("\n");

    // Call assembly function
    daxpy(n, A, X, Y, Z);

    // Display result (up to first 10 elements)
    printf("\nResult (First 10 Elements):\n");
    for (int i = 0; i < (n < 10 ? n : 10); i++) {
        printf("Z[%d] = %.2f\n", i, Z[i]);
    }

}