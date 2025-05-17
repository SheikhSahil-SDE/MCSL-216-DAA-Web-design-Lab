// Q6. Implement the Stassen’s multiplication algorithm two matrices A and B of n* n, 
// where n is a power of 2 on different problem instances and compare it (all the instances) in 
// terms of a number of multiplications and additions required.


#include <stdio.h>
#include <stdlib.h>

// Global counters
long long multiplications = 0;
long long additions = 0;

// Allocate matrix
int** allocateMatrix(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        matrix[i] = (int*)malloc(n * sizeof(int));
    return matrix;
}

// Free matrix
void freeMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
}

// Matrix addition/subtraction
void matrixAddSubtract(int** A, int** B, int** result, int n, int subtract) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] + (subtract ? -B[i][j] : B[i][j]);
            additions++;
        }
}

// Strassen's matrix multiplication
void strassen(int** A, int** B, int** C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        multiplications++;
        return;
    }

    int k = n / 2;
    int** A11 = allocateMatrix(k);
    int** A12 = allocateMatrix(k);
    int** A21 = allocateMatrix(k);
    int** A22 = allocateMatrix(k);
    int** B11 =.allocateMatrix(k);
    int** B12 = allocateMatrix(k);
    int** B21 = allocateMatrix(k);
    int** B22 = allocateMatrix(k);
    int** P1 = allocateMatrix(k);
    int** P2 = allocateMatrix(k);
    int** P3 = allocateMatrix(k);
    int** P4 = allocateMatrix(k);
    int** P5 = allocateMatrix(k);
    int** P6 = allocateMatrix(k);
    int** P7 = allocateMatrix(k);
    int** temp1 = allocateMatrix(k);
    int** temp2 = allocateMatrix(k);

    // Divide matrices
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }

    // P1 = (A11 + A22) * (B11 + B22)
    matrixAddSubtract(A11, A22, temp1, k, 0);
    matrixAddSubtract(B11, B22, temp2, k, 0);
    strassen(temp1, temp2, P1, k);

    // P2 = (A21 + A22) * B11
    matrixAddSubtract(A21, A22, temp1, k, 0);
    strassen(temp1, B11, P2, k);

    // P3 = A11 * (B12 - B22)
    matrixAddSubtract(B12, B22, temp1, k, 1);
    strassen(A11, temp1, P3, k);

    // P4 = A22 * (B21 - B11)
    matrixAddSubtract(B21, B11, temp1, k, 1);
    strassen(A22, temp1, P4, k);

    // P5 = (A11 + A12) * B22
    matrixAddSubtract(A11, A12, temp1, k, 0);
    strassen(temp1, B22, P5, k);

    // P6 = (A21 - A11) * (B11 + B12)
    matrixAddSubtract(A21, A11, temp1, k, 1);
    matrixAddSubtract(B11, B12, temp2, k, 0);
    strassen(temp1, temp2, P6, k);

    // P7 = (A12 - A22) * (B21 + B22)
    matrixAddSubtract(A12, A22, temp1, k, 1);
    matrixAddSubtract(B21, B22, temp2, k, 0);
    strassen(temp1, temp2, P7, k);

    // Compute C11 = P1 + P4 - P5 + P7
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j] = P1[i][j] + P4[i][j] - P5[i][j] + P7[i][j];
            additions += 3;
        }

    // Compute C12 = P3 + P5
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j + k] = P3[i][j] + P5[i][j];
            additions++;
        }

    // Compute C21 = P2 + P4
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i + k][j] = P2[i][j] + P4[i][j];
            additions++;
        }

    // Compute C22 = P1 - P2 + P3 + P6
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i + k][j + k] = P1[i][j] - P2[i][j] + P3[i][j] + P6[i][j];
            additions += 3;
        }

    // Free memory
    freeMatrix(A11, k); freeMatrix(A12, k); freeMatrix(A21, k); freeMatrix(A22, k);
    freeMatrix(B11, k); freeMatrix(B12, k); freeMatrix(B21, k); freeMatrix(B22, k);
    freeMatrix(P1, k); freeMatrix(P2, k); freeMatrix(P3, k); freeMatrix(P4, k);
    freeMatrix(P5, k); freeMatrix(P6, k); freeMatrix(P7, k);
    freeMatrix(temp1, k); freeMatrix(temp2, k);
}

// Standard matrix multiplication for comparison
void standardMultiply(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
                multiplications++;
                additions++;
            }
        }
}

int main() {
    int sizes[] = {2, 4, 8};
    int num_sizes = 3;

    for (int s = 0; s < num_sizes; s++) {
        int n = sizes[s];
        printf("\nQ6: Strassen’s Matrix Multiplication for n=%d\n", n);

        // Allocate matrices
        int** A = allocateMatrix(n);
        int** B = allocateMatrix(n);
        int** C = allocateMatrix(n);

        // Initialize matrices (example values)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                A[i][j] = i + j + 1;
                B[i][j] = i - j + 1;
                C[i][j] = 0;
            }

        // Strassen’s
        multiplications = 0;
        additions = 0;
        strassen(A, B, C, n);
        printf("Strassen’s Algorithm:\n");
        printf("Multiplications: %lld\n", multiplications);
        printf("Additions/Subtractions: %lld\n", additions);

        // Standard
        multiplications = 0;
        additions = 0;
        standardMultiply(A, B, C, n);
        printf("Standard Algorithm:\n");
        printf("Multiplications: %lld\n", multiplications);
        printf("Additions/Subtractions: %lld\n", additions - n * n);

        // Free matrices
        freeMatrix(A, n);
        freeMatrix(B, n);
        freeMatrix(C, n);
    }

    return 0;
}