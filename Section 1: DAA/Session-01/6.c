// Q6. Implement Selection Sort algorithm on a similar set of data as in Q5 and
// (i) Perform similar operations on the above example
// (ii) make a comparison between the two algorithms in terms of best case and worst case complexities.



#include <stdio.h>

void selection_sort(int A[], int n, int *comp_count, int *swap_count, int *outer_loop_count, int *inner_loop_count) {
    *comp_count = 0;
    *swap_count = 0;
    *outer_loop_count = 0;
    *inner_loop_count = 0;
    
    for (int i = 0; i < n-1; i++) {
        (*outer_loop_count)++;
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            (*inner_loop_count)++;
            (*comp_count)++;
            if (A[j] < A[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            // Swap A[i] and A[min_idx]
            int temp = A[i];
            A[i] = A[min_idx];
            A[min_idx] = temp;
            (*swap_count)++;
        }
    }
}

int main() {
    int A[] = {55, 25, 15, 40, 60, 35, 17, 65, 75, 10};
    int n = 10;
    int comp_ops, swap_ops, outer_loops, inner_loops;
    
    selection_sort(A, n, &comp_ops, &swap_ops, &outer_loops, &inner_loops);
    
    printf("Q6:\n");
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("(i) Number of exchange operations: %d\n", swap_ops);
    printf("Number of comparison operations: %d\n", comp_ops);
    printf("Outer loop iterations: %d\n", outer_loops);
    printf("Inner loop iterations: %d\n", inner_loops);
    
    return 0;
}