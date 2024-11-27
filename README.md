# DAXPY Kernel Performance Evaluation

This repository contains the implementation of the **DAXPY operation** using both **C** and **Assembly** kernels. The goal is to evaluate the performance of the operation under different configurations, analyze the execution time, and compare the performance of the two kernels.

## DAXPY Operation

The **DAXPY** (Double Precision A·X Plus Y) operation is a basic vector operation defined as: Y[i] = A * X[i] + Y[i]

Where:
- `A` is a scalar constant.
- `X[i]` and `Y[i]` are the `i-th` elements of vectors `X` and `Y`.

This operation is commonly used in scientific computing and numerical simulations.

## How to Run the Project

1. **Clone the repository**:
   git clone https://github.com/BautistaRalphh/LBYARCH-MP2.git


2. **Ensure GCC and NASM are installed and added to your system's PATH**:
   - Check by running:
     gcc --version
     nasm --version

3. **Run the batch script** (`assemble.bat`) to build the project:
   assemble.bat

## Input and Output Details

### Input
The program expects the following inputs during execution:

1. **Choice of Vector Size**  
   The user is prompted to choose a vector size for the DAXPY operation: 
		Options: A) 2^20 B) 2^24 C) 2^28 D) 2^29
		Enter the corresponding option (`A`, `B`, `C`, or `D`) to proceed.

2. **Scalar Values for Each Loop Iteration**  
For each iteration of the DAXPY computation, the user is prompted to input a scalar value `A`, used in the formula: Z[i] = A * X[i] + Y[i]

### Output
The program provides the following outputs for each iteration:

1. **Result Vector `Z` (First 10 Values Only)**  
Displays the first 10 computed values of the result vector `Z`:
		Z[0] = <value> 
		Z[1] = <value> 
		... 
		Z[9] = <value>


2. **Execution Time for Each Iteration**  
Shows the runtime of the DAXPY computation in seconds:
		Run <iteration> execution time: <time> seconds


3. **Comparison with C Implementation**  
Validates the SASM (assembly) output against the C implementation:
		C Result[<iteration>] 
		(First 10 values only): 
		Z_c[0] = <value> 
		Z_c[1] = <value> 
		... 
		Z_c[9] = <value>
		
		SASM output matches C output for loop#<iteration>.
		
## Comparative Execution Time

Below is a summary of the execution times (in seconds) for various runs of the DAXPY operation with different scalar values:

| Run # | Execution Time (seconds) |
|-------|--------------------------|
| 1     | 9.344                    |
| 2     | 4.414                    |
| 3     | 0.868                    |
| 4     | 1.685                    |
| 5     | 0.587                    |
| 6     | 0.771                    |
| 7     | 0.732                    |
| 8     | 0.636                    |
| 9     | 0.558                    |
| 10    | 0.612                    |
| 11    | 0.433                    |
| 12    | 0.395                    |
| 13    | 0.427                    |
| 14    | 0.716                    |
| 15    | 0.602                    |
| 16    | 1.157                    |
| 17    | 0.611                    |

## Performance Analysis

### Observations
- **Execution times vary** based on the scalar value, reflecting differences in computational complexity.
- Runs with **larger scalar values** (e.g., **Run 1**) take longer due to more intensive computations.
- Runs with **smaller scalars** (e.g., **Run 11–17**) are faster, indicating reduced computational effort.

### Consistency and Accuracy
- Both the **C** and **Assembly kernels** produce matching outputs, verifying the **accuracy and consistency** of the Assembly implementation.

## Authors

- **Bautista, Ralph Gabriel R.**
- **Lopez, Ghee Kaye S.**
