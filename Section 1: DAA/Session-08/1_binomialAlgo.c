#include <stdio.h>

// Function to compute minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Divide and Conquer function to compute C(n, k)
long long binomialCoefficient(int n, int k, int depth) {
    // Print the current recursive call
    for (int i = 0; i < depth; i++) printf("  ");
    printf("Computing C(%d, %d)\n", n, k);

    // Base cases
    if (k == 0 || k == n) {
        for (int i = 0; i < depth; i++) printf("  ");
        printf("Base case: C(%d, %d) = 1\n", n, k);
        return 1;
    }
    if (k < 0 || k > n) {
        for (int i = 0; i < depth; i++) printf("  ");
        printf("Base case: C(%d, %d) = 0\n", n, k);
        return 0;
    }

    // Use symmetry to reduce computation: C(n, k) = C(n, n-k)
    k = min(k, n - k);
    for (int i = 0; i < depth; i++) printf("  ");
    printf("Optimized k to %d using symmetry\n", k);

    // Recursive calls
    long long left = binomialCoefficient(n - 1, k - 1, depth + 1);
    long long right = binomialCoefficient(n - 1, k, depth + 1);

    // Combine results
    long long result = left + right;
    for (int i = 0; i < depth; i++) printf("  ");
    printf("C(%d, %d) = C(%d, %d) + C(%d, %d) = %lld + %lld = %lld\n", 
           n, k, n-1, k-1, n-1, k, left, right, result);
    return result;
}

int main() {
    int n, k;
    printf("\nSession 8: Implementation of Binomial Coefficient Algorithm\n");
    printf("\nQ1: Binomial Coefficient using Divide and Conquer\n");
    printf("\nEnter values of n and k to compute C(n, k): ");
    scanf("%d %d", &n, &k);

    printf("\nIntermediate Steps:\n");
    long long result = binomialCoefficient(n, k, 0);
    printf("\nFinal Result: C(%d, %d) = %lld\n\n", n, k, result);
    return 0;
}
