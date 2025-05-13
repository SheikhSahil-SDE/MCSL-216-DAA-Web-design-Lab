
//Q4. Implement left to right and right to left binary exponentiation methods for the following problems:
    // (i) 4^512
    // (ii) 3^31
    // Calculate the followings for problems (i) and (ii) How many times the loops will be executed? 
    // How many times will the multiplication and addition operations be executed?



#include <stdio.h>


long long left_to_right_exp(long long x, long long n, long long mod, int *mul_count) {
   long long result = 1;
   *mul_count = 0;
   while (n > 0) {
       if (n & 1) { // If current bit is 1
           result = (result * x) % mod;
           (*mul_count)++; // Count multiplication by base
       }
       x = (x * x) % mod; // Square the base
       (*mul_count)++; // Count squaring
       n >>= 1; // Shift right
   }
   return result;
}


long long right_to_left_exp(long long x, long long n, long long mod, int *mul_count) {
   long long result = 1;
   long long base = x;
   *mul_count = 0;
   while (n > 0) {
       if (n & 1) { // If current bit is 1
           result = (result * base) % mod;
           (*mul_count)++; // Count multiplication by base
       }
       base = (base * base) % mod; // Square the base
       (*mul_count)++; // Count squaring
       n >>= 1; // Shift right
   }
   return result;
}


int main() {
   long long mod = 1000000007; // 10^9 + 7
   int mul_count_lr, mul_count_rl;
  
   // Compute 4^512
   long long result_lr_4_512 = left_to_right_exp(4, 512, mod, &mul_count_lr);
   long long result_rl_4_512 = right_to_left_exp(4, 512, mod, &mul_count_rl);
   printf("Q4:\n");
   printf("(i) 4^512 mod %lld:\n", mod);
   printf("Left-to-Right: %lld, Multiplications: %d\n", result_lr_4_512, mul_count_lr);
   printf("Right-to-Left: %lld, Multiplications: %d\n", result_rl_4_512, mul_count_rl);
  
   // Compute 3^31
   long long result_lr_3_31 = left_to_right_exp(3, 31, mod, &mul_count_lr);
   long long result_rl_3_31 = right_to_left_exp(3, 31, mod, &mul_count_rl);
   printf("(ii) 3^31 mod %lld:\n", mod);
   printf("Left-to-Right: %lld, Multiplications: %d\n", result_lr_3_31, mul_count_lr);
   printf("Right-to-Left: %lld, Multiplications: %d\n", result_rl_3_31, mul_count_rl);
  
   return 0;
}
