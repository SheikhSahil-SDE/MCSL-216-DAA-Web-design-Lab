// Q2(i). Implement Horner’s rule for evaluating the polynomial 
    // P(x)= 6𝑥^6+5𝑥^5 + 4𝑥^4 -3𝑥^3 + 2𝑥^2+ 8𝑥 − 7 at x = 3. Calculate how many times 
// (i) multiplications and addition operations will take 
// (ii) how many times the loop will iterate?


#include <stdio.h>
int horner(int coefficients[], int n, int x, int *mul_count, int *add_count) {
   int result = coefficients[0];
   *mul_count = 0;
   *add_count = 0;
   for (int i = 1; i <= n; i++) {
       result = result * x + coefficients[i];
       (*mul_count)++;
       (*add_count)++;
   }
   return result;
}
int main() {
   int coefficients[] = {6, 5, 4, -3, 2, 8, -7}; // a_6 to a_0
   int n = 6; // degree
   int x = 3;
   int mul_ops, add_ops;
   int result = horner(coefficients, n, x, &mul_ops, &add_ops);
   printf("Q2(i):\n");
   printf("P(3) = %d\n", result);
   printf("Number of multiplications: %d\n", mul_ops);
   printf("Number of additions: %d\n", add_ops);
   printf("Number of loop iterations: %d\n", n);
   return 0;
}
