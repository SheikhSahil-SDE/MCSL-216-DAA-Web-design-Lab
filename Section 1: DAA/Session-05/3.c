// Q3. Implement the Merge Sort algorithm to sort the following list, showing the process step by step. 

//                             200 150 50 100 75 25 10 5 
                            
//     Draw a tree of recursive calls in this problem.

#include <stdio.h>
#include <stdlib.h>

// Merge function to combine two sorted subarrays
void merge(int arr[], int left, int mid, int right, int depth) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Temporary arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Merge the temporary arrays back
    int i = 0, j = 0, k = left;
    printf("Depth %d: Merging [%d, %d] and [%d, %d]: ", depth, left, mid, mid + 1, right);
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copy remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    // Print array state
    printf("Result: ");
    for (int x = left; x <= right; x++)
        printf("%d ", arr[x]);
    printf("\n");
    
    free(L);
    free(R);
}

// Merge Sort function
void mergeSort(int arr[], int left, int right, int depth) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        printf("Depth %d: Splitting [%d, %d] into [%d, %d] and [%d, %d]\n", 
               depth, left, right, left, mid, mid + 1, right);
        
        // Recursive calls
        mergeSort(arr, left, mid, depth + 1);
        mergeSort(arr, mid + 1, right, depth + 1);
        
        // Merge the sorted halves
        merge(arr, left, mid, right, depth);
    } else {
        printf("Depth %d: Base case [%d, %d]: %d\n", depth, left, right, arr[left]);
    }
}

int main() {
    int arr[] = {200, 150, 50, 100, 75, 25, 10, 5};
    int n = 8;
    
    printf("Q3: Merge Sort\n");
    printf("Original Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
    
    mergeSort(arr, 0, n - 1, 0);
    
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}