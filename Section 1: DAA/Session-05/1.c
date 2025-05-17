// Q1 Implement a recursive binary search algorithm on your system to search for the number 100 in the 
// following array of integers. Show the processes step by step: 
                    
//                     10 35 40 45 50 55 60 65 70 100

// Draw recursive calls to be made in this problem.




#include <stdio.h>


// Recursive binary search function
int binarySearch(int arr[], int target, int left, int right, int depth) {
   // Base case: invalid range
   if (left > right) {
       printf("Depth %d: left=%d, right=%d, range invalid, return -1\n", depth, left, right);
       return -1;
   }
  
   // Compute middle index
   int mid = (left + right) / 2;
   printf("Depth %d: left=%d, right=%d, mid=%d, arr[mid]=%d\n", depth, left, right, mid, arr[mid]);
  
   // Base case: target found
   if (arr[mid] == target) {
       printf("Depth %d: Target %d found at index %d\n", depth, target, mid);
       return mid;
   }
  
   // Recursive cases
   if (arr[mid] > target) {
       printf("Depth %d: arr[mid]=%d > target=%d, search left half\n", depth, arr[mid], target);
       return binarySearch(arr, target, left, mid - 1, depth + 1);
   } else {
       printf("Depth %d: arr[mid]=%d < target=%d, search right half\n", depth, arr[mid], target);
       return binarySearch(arr, target, mid + 1, right, depth + 1);
   }
}


int main() {
   int arr[] = {10, 35, 40, 45, 50, 55, 60, 65, 70, 100};
   int n = 10;
   int target = 100;
  
   printf("Q1: Recursive Binary Search for %d\n", target);
   printf("Array: ");
   for (int i = 0; i < n; i++) {
       printf("%d ", arr[i]);
   }
   printf("\n\n");
  
   int result = binarySearch(arr, target, 0, n - 1, 0);
  
   printf("\nFinal Result: ");
   if (result != -1) {
       printf("Element %d found at index %d\n", target, result);
   } else {
       printf("Element %d not found\n", target);
   }
  
   return 0;
}
