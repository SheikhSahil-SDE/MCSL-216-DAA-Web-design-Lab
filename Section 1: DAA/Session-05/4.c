// Q4 Implement Quick Sort’s algorithm on your machine to do sorting of the following list of elements 
                
//                             12 20 22 16 25 18 8 10 6 15 

// Show step-by-step processes.

#include <stdio.h>

// Swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function using last element as pivot
int partition(int arr[], int left, int right, int depth) {
    int pivot = arr[right];
    int i = left - 1;
    
    printf("Depth %d: Partitioning [%d, %d], pivot=%d, array: ", depth, left, right, pivot);
    for (int k = left; k <= right; k++)
        printf("%d ", arr[k]);
    printf("\n");
    
    for (int j = left; j < right; j++) {
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

// Quick Sort function
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
    int arr[] = {12, 20, 22, 16, 25, 18, 8, 10, 6, 15};
    int n = 10;
    
    printf("Q4: Quick Sort\n");
    printf("Original Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
    
    quickSort(arr, 0, n - 1, 0);
    
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}