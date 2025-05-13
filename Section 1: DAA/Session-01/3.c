// Q3.Implement multiplication of two matrices A[4,4] and B[4,4] and calculate
//    (i) how many times the innermost and the outermost loops will run
//    (ii) total number of multiplications and additions in computing the multiplication



#include <stdio.h>


void matrix_multiply(int A[4][4], int B[4][4], int C[4][4], int *mul_count, int *add_count, int *outer_loop_count, int *inner_loop_count) {
   *mul_count = 0;
   *add_count = 0;
   *outer_loop_count = 0;
   *inner_loop_count = 0;
  
   for (int i = 0; i < 4; i++) {
       (*outer_loop_count)++; // Count outermost loop iterations
       for (int j = 0; j < 4; j++) {
           C[i][j] = 0; // Initialize C[i][j]
           for (int k = 0; k < 4; k++) {
               (*inner_loop_count)++; // Count innermost loop iterations
               C[i][j] += A[i][k] * B[k][j];
               (*mul_count)++; // Count multiplication
               (*add_count)++; // Count addition
           }
       }
   }
}


int main() {
   // Example matrices A and B
   int A[4][4] = {
       {1, 2, 3, 4},
       {5, 6, 7, 8},
       {9, 10, 11, 12},
       {13, 14, 15, 16}
   };
   int B[4][4] = {
       {16, 15, 14, 13},
       {12, 11, 10, 9},
       {8, 7, 6, 5},
       {4, 3, 2, 1}
   };
   int C[4][4]; // Result matrix
   int mul_ops, add_ops, outer_loops, inner_loops;
  
   matrix_multiply(A, B, C, &mul_ops, &add_ops, &outer_loops, &inner_loops);
  
   printf("Q3:\n");
   printf("Resultant Matrix C:\n");
   for (int i = 0; i < 4; i++) {
       for (int j = 0; j < 4; j++) {
           printf("%d ", C[i][j]);
       }
       printf("\n");
   }
   printf("(i) Outermost loop iterations: %d\n", outer_loops);
   printf("Innermost loop iterations: %d\n", inner_loops);
   printf("(ii) Total multiplications: %d\n", mul_ops);
   printf("Total additions: %d\n", add_ops);
  
   return 0;
}
