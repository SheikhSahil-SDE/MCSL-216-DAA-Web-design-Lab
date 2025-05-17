// Q5. Examine the performance of the Quick Sort algorithm implemented in the previous problem for the following list in terms of the number of comparisons, exchange operations, and the number of times the loop will iterate. 

//                             6 8 10 12 15 16 18 20 22 25

#include <stdio.h>

// Global counters
long long comparisons = 0;
long long swaps = 0;
long long loop_iterations = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

int partition(int arr[], int left, int right, int depth) {
    int pivot = arr[right];
    int i = left - 1;
    
    printf("Depth %d: Partitioning [%d, %d], pivot=%d, array: ", depth, left, right, pivot);
    for (int k = left; k <= right; k++)
        printf("%d ", arr[k]);
    printf("\n");
    
    for (int j = left; j < right; j++) {
        loop_iterations++;
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    
    printf("Depth %d: After partition, pivot at index %d, array: ", depth, i + 1);
    for (int k = left; k <= right; k++)
        printf("%d ", arr[k]);
    printf("\n");
    
    return i + 1;
}

void quickSort(int arr[], int left, int right, int depth) {
    if (left < right) {
        printf("Depth %d: quickSort(%d, %d)\n", depth, left, right);
        int pivotIndex = partition(arr, left, right, depth);
        quickSort(arr, left, pivotIndex - 1, depth + 1);
        quickSort(arr, pivotIndex + 1, right, depth + 1);
    } else if (left == right) {
        printf("Depth %d: Base case [%d, %d]: %d\n", depth, left, right, arr[left]);
    } else {
        printf("Depth %d: Empty range [%d, %d]\n", depth, left, right);
    }
}

int main() {
    int arr[] = {6, 8, 10, 12, 15, 16, 18, 20, 22, 25};
    int n = 10;
    
    printf("Q5: Quick Sort Performance\n");
    printf("Original Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
    
    quickSort(arr, 0, n - 1, 0);
    
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\nPerformance Metrics:\n");
    printf("Comparisons: %lld\n", comparisons);
    printf("Swaps: %lld\n", swaps);
    printf("Loop Iterations: %lld\n", loop_iterations);
    
    return 0;
}