// Q1. Implement Euclid’s algorithm to find GCD (15265, 15)and calculate the number of 
// times mod and assignment operations will be required.



#include <stdio.h>
int euclidean_gcd(int a, int b, int *mod_count, int *assign_count) {
*mod_count = 0;
*assign_count = 0;
while (b) {
(*mod_count)++;
int temp = b;
b = a % b;
a = temp;
(*assign_count) += 2;
}
return a;
}
int main() {
int gcd_result, mod_ops, assign_ops;
gcd_result = euclidean_gcd(15265, 15, &mod_ops, &assign_ops);
printf("Q1:\n");
printf("GCD(15265, 15) = %d\n", gcd_result);
printf("Number of modulo operations: %d\n", mod_ops);
printf("Number of assignment operations: %d\n", assign_ops);
return 0;
}
