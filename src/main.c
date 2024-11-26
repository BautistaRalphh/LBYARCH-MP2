#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void daxpy(double *X, double *Y, double *Z, int n, double A);

int main() {
    int n, i, j;
    double *X, *Y, *Z, A;
    clock_t start, end;
    double total_time = 0.0, avg_time, run_time;

    // Predefined sizes for testing
    int sizes[] = {1 << 20, 1 << 24, 1 << 28, 1 << 29}; // 2^20, 2^24, 2^28, 2^29

    char choice;
    
    // Ask the user to choose a vector size (A, B, C, D)
    printf("Choose a vector size to test:\n");
    printf("A) 2^20\n");
    printf("B) 2^24\n");
    printf("C) 2^28\n");
    printf("D) 2^29\n");
    printf("Enter your choice (A/B/C/D): ");
    if (scanf(" %c", &choice) != 1) {
        printf("Invalid input.\n");
        return -1;
    }

    // Determine the vector size based on the user's choice
    switch(choice) {
        case 'A': case 'a':
            n = sizes[0];
            break;
        case 'B': case 'b':
            n = sizes[1];
            break;
        case 'C': case 'c':
            n = sizes[2];
            break;
        case 'D': case 'd':
            n = sizes[3];
            break;
        default:
            printf("Invalid choice.\n");
            return -1;
    }

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

    // Initialize vector X and Y with default values
    for (i = 0; i < n; i++) {
        X[i] = (double)i;       
        Y[i] = (double)(i + 10); 
    }

    // Run daxpy 30 times and time the kernel portion
    for (j = 0; j < 30; j++) {

        start = clock(); 

        // Ask the user for the scalar value to use for this loop
        printf("Enter the scalar value for the daxpy operation (A) in loop#%d: ", j);
        if (scanf("%lf", &A) != 1) {
            printf("Invalid input for scalar value.\n");
            return -1;
        }

        daxpy(X, Y, Z, n, A);

        // Print results (show first 10 values of Z)
        printf("\nResult[%d] (First 10 values only):\n", j);
        for (i = 0; i < (n < 10 ? n : 10); i++) {
            printf("Z[%d] = %.2lf\n", i, Z[i]);
        }

        end = clock();

        run_time = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Run %d execution time: %.6f seconds\n", j + 1, run_time);

        total_time += run_time; 

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
