#include <stdio.h>

// Function to compute minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Dynamic Programming (space-optimized) to compute C(n, k)
long long binomialCoefficientDP(int n, int k) {
    // Use symmetry: C(n, k) = C(n, n-k)
    k = min(k, n - k);
    printf("Optimized k to %d using symmetry\n", k);

    // DP array: dp[j] represents C(i, j) at step i
    long long dp[k + 1];
    
    // Initialize base case: C(i, 0) = 1 for all i
    for (int j = 0; j <= k; j++) {
        dp[j] = (j == 0) ? 1 : 0;
    }

    printf("\nIntermediate DP Array Steps:\n");
    printf("Initial DP Array (i=0): ");
    for (int j = 0; j <= k; j++) {
        printf("C(0,%d)=%lld ", j, dp[j]);
    }
    printf("\n");

    // Compute C(i, j) for i from 1 to n
    for (int i = 1; i <= n; i++) {
        // Update dp[j] from right to left to avoid overwriting values
        for (int j = min(i, k); j >= 1; j--) {
            dp[j] = dp[j] + dp[j - 1]; // C(i,j) = C(i-1,j) + C(i-1,j-1)
        }
        // Print the DP array after each iteration
        printf("After i=%d: ", i);
        for (int j = 0; j <= min(i, k); j++) {
            printf("C(%d,%d)=%lld ", i, j, dp[j]);
        }
        printf("\n");
    }

    return dp[k];
}

int main() {
    int n, k;
    printf("\nSession 8: Implementation of Binomial Coefficient Algorithm\n");
    printf("\nQ2: Binomial Coefficient using Dynamic Programming\n");
    printf("\nEnter values of n and k to compute C(n, k): ");
    scanf("%d %d", &n, &k);

    printf("\nIntermediate Steps:\n");
    long long result = binomialCoefficientDP(n, k);
    printf("\nFinal Result: C(%d, %d) = %lld\n\n", n, k, result);
    return 0;
}
