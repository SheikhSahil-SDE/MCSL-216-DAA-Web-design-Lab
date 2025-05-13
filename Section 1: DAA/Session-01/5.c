// Q5. Implement the Bubble Sort algorithm for the following list of numbers:
//                  55 25 15 40 60 35 17 65 75 10
// Calculate
// (i) a number of exchange operations
// (ii) a number of times comparison operations
// (iii) a number of times the inner and outer loops will iterate?


#include <stdio.h>


void bubble_sort(int A[], int n, int *comp_count, int *swap_count, int *outer_loop_count, int *inner_loop_count) {
   *comp_count = 0;
   *swap_count = 0;
   *outer_loop_count = 0;
   *inner_loop_count = 0;
  
   for (int i = 0; i < n-1; i++) {
       (*outer_loop_count)++;
       for (int j = 0; j < n-i-1; j++) {
           (*inner_loop_count)++;
           (*comp_count)++;
           if (A[j] > A[j+1]) {
               // Swap A[j] and A[j+1]
               int temp = A[j];
               A[j] = A[j+1];
               A[j+1] = temp;
               (*swap_count)++;
           }
       }
   }
}


int main() {
   int A[] = {55, 25, 15, 40, 60, 35, 17, 65, 75, 10};
   int n = 10;
   int comp_ops, swap_ops, outer_loops, inner_loops;
  
   bubble_sort(A, n, &comp_ops, &swap_ops, &outer_loops, &inner_loops);
     printf("Q5:\n");
   printf("Sorted Array: ");
   for (int i = 0; i < n; i++) {
       printf("%d ", A[i]);
   }
   printf("\n");
   printf("(i) Number of exchange operations: %d\n", swap_ops);
   printf("(ii) Number of comparison operations: %d\n", comp_ops);
   printf("(iii) Outer loop iterations: %d\n", outer_loops);
   printf("Inner loop iterations: %d\n", inner_loops);  
   return 0;
}
