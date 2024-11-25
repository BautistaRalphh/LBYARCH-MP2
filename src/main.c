#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void daxpy(double *X, double *Y, double *Z, int n, double A);

int main() {
    int n, i, j;
    double *X, *Y, *Z, A;
	clock_t start, end;
    double total_time, avg_time, run_time;

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
	
	total_time = 0.0;
	// Run daxpy 30 times and time the kernel portion
    for (j = 0; j < 30; j++) {
        start = clock(); // Start timing
        daxpy(X, Y, Z, n, A); // Kernel operation
        end = clock(); // End timing

        // Calculate elapsed time for the kernel for this run
        run_time = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Print runtime for this individual run
        // printf("Run %d execution time: %.6f seconds\n", j + 1, run_time);

        total_time += run_time; // Add the run time to total time
    }

    
	avg_time = total_time / 30.0; // Average execution time
    printf("\nAverage execution time for vector size n = %d: %.6f seconds\n", n, avg_time);


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
