#include <stdio.h>

int operations_dp = 0; // Counter for array updates

int min(int a, int b) {
    return (a < b) ? a : b;
}

long long binomialCoefficientDP(int n, int k) {
    k = min(k, n - k);
    long long dp[k + 1];
    for (int j = 0; j <= k; j++) {
        dp[j] = (j == 0) ? 1 : 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j >= 1; j--) {
            dp[j] = dp[j] + dp[j - 1];
            operations_dp++; // Increment for each array update
        }
    }
    return dp[k];
}

int main() {
    int n, k;
    printf("\nSession 8: Implementation of Binomial Coefficient Algorithm\n");
    printf("\nQ3: Performance Analysis - Dynamic Programming\n");
    printf("\nEnter values of n and k to compute C(n, k): ");
    scanf("%d %d", &n, &k);

    operations_dp = 0;
    long long result = binomialCoefficientDP(n, k);
    printf("C(%d, %d) = %lld\n", n, k, result);
    printf("Operations (array updates): %d\n\n", operations_dp);
    return 0;
}

