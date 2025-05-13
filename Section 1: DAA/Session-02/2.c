// Q2 (P1, P2, P3, P4, P5) = (20, 30,40, 32, 55)
// (W1, W2, W3, W4, W5) = (5, 8, 10 12, 15)
// Maximum Knapsack Capacity = 20


#include <stdio.h>
#include <stdlib.h>


// Structure to hold item details
typedef struct {
   int index;
   double profit;
   double weight;
   double ratio;
} Item;


// Comparison function for qsort (descending order of ratio)
int compare(const void *a, const void *b) {
   Item *itemA = (Item *)a;
   Item *itemB = (Item *)b;
   if (itemA->ratio < itemB->ratio) return 1;
   if (itemA->ratio > itemB->ratio) return -1;
   return 0;
}


double fractional_knapsack(double profits[], double weights[], int n, double capacity) {
   // Create array of items
   Item items[n];
   for (int i = 0; i < n; i++) {
       items[i].index = i + 1;
       items[i].profit = profits[i];
       items[i].weight = weights[i];
       items[i].ratio = profits[i] / weights[i];
   }
  
   // Sort items by ratio in descending order
   qsort(items, n, sizeof(Item), compare);
  
   double total_profit = 0.0;
   double remaining_capacity = capacity;
  
   // Process items
   for (int i = 0; i < n; i++) {
       if (remaining_capacity >= items[i].weight) {
           // Take full item
           total_profit += items[i].profit;
           remaining_capacity -= items[i].weight;
       } else if (remaining_capacity > 0) {
           // Take fraction of item
           double fraction = remaining_capacity / items[i].weight;
           total_profit += fraction * items[i].profit;
           remaining_capacity = 0;
       } else {
           break;
       }
   }
  
   return total_profit;
}


int main() {
   double profits[] = {20, 30, 40, 32, 55};
   double weights[] = {5, 8, 10, 12, 15};
   int n = 5;
   double capacity = 20;
  
   double max_profit = fractional_knapsack(profits, weights, n, capacity);
  
   printf("\n Q2:\n");
   printf("\n Maximum Profit: %.2f \n \n", max_profit);
  
   return 0;
}
