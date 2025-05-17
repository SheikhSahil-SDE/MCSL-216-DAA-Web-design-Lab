#include <stdio.h>

int operations_dnc = 0; // Counter for recursive calls

int min(int a, int b) {
    return (a < b) ? a : b;
}

long long binomialCoefficientDNC(int n, int k, int depth) {
    operations_dnc++; // Increment for each recursive call

    if (k == 0 || k == n) return 1;
    if (k < 0 || k > n) return 0;

    k = min(k, n - k);
    return binomialCoefficientDNC(n - 1, k - 1, depth + 1) + binomialCoefficientDNC(n - 1, k, depth + 1);
}

int main() {
    int n, k;
    printf("\nSession 8: Implementation of Binomial Coefficient Algorithm\n");
    printf("\nQ3: Performance Analysis - Divide and Conquer\n");
    printf("\nEnter values of n and k to compute C(n, k): ");
    scanf("%d %d", &n, &k);

    operations_dnc = 0;
    long long result = binomialCoefficientDNC(n, k, 0);
    printf("C(%d, %d) = %lld\n", n, k, result);
    printf("Operations (recursive calls): %d\n\n", operations_dnc);
    return 0;
}
