#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void daxpy(double *X, double *Y, double *Z, int n, double A);

int main() {
    int n, i, j;
    double *X, *Y, *Z, A;
    clock_t start, end;
    double total_time = 0.0, avg_time, run_time;

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

    // Run daxpy 30 times and time the kernel portion
    for (j = 0; j < 30; j++) {
        
        start = clock(); // Start timing

        printf("\nEnter the scalar value you for this loop (A): ");
        if (scanf("%lf", &A) != 1) {
            printf("Invalid input for scalar value.\n");
            return -1;
        }

        daxpy(X, Y, Z, n, A); // Kernel operation

        // Print results
        printf("\nResult[%d]:\n", j);
        for (i = 0; i < (n < 10 ? n : 10); i++) {
            printf("Z[%d] = %.2lf\n", i, Z[i]);
        }

        end = clock(); // End timing

        run_time = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Run %d execution time: %.6f seconds\n", j + 1, run_time);

        total_time += run_time; 

        // Increment the values of X and Y each loop
        for (i = 0; i < n; i++) {
            X[i] = X[i] + 1;
            Y[i] = Y[i] + 1;
        }

    }

    avg_time = total_time / 30.0; 
    printf("\nAverage execution time for vector size n = %d: %.6f seconds\n", n, avg_time);

    free(X);
    free(Y);
    free(Z);

    return 0;
}
