// Q3. Consider the following jobs, deadlines, and profits. Implement the task scheduling 
// algorithm with deadlines to maximize the total profits.

// Jobs 		Deadlines		Profit 
//    1			3		   50
//    2 			4		   20
//    3			5		   70
//    4			3	  	   15
//    5			2		   10
//    6			1		   47
//    7			1		   60


#include <stdio.h>
#include <stdlib.h>


// Structure to hold job details
typedef struct {
   int id; // Job ID (1-based)
   int deadline;
   int profit;
} Job;


// Comparison function for qsort (descending order of profit)
int compare(const void *a, const void *b) {
   Job *jobA = (Job *)a;
   Job *jobB = (Job *)b;
   return jobB->profit - jobA->profit;
}


void schedule_jobs(Job jobs[], int n, int max_deadline) {
   // Sort jobs by profit in descending order
   qsort(jobs, n, sizeof(Job), compare);
  
   // Initialize slots (0 means free)
   int *slots = (int *)calloc(max_deadline + 1, sizeof(int));
   int total_profit = 0;
  
   // Schedule jobs in latest possible slot
   for (int i = 0; i < n; i++) {
       // Find latest free slot <= deadline
       for (int t = jobs[i].deadline; t >= 1; t--) {
           if (slots[t] == 0) {
               slots[t] = jobs[i].id;
               total_profit += jobs[i].profit;
               break;
           }
       }
   }
  
   // Print schedule and total profit
   printf("\nQ3:\n");
   printf("\nOptimal Schedule:\n");
   for (int t = 1; t <= max_deadline; t++) {
       if (slots[t] != 0) {
           printf("Time Slot %d: J%d (Profit %d)\n", t, slots[t], jobs[slots[t]-1].profit);
       }
   }
   printf("\nTotal Profit: %d \n \n", total_profit);
  
   free(slots);
}


int main() {
   Job jobs[] = {{1, 3, 50}, {2, 4, 20}, {3, 5, 70}, {4, 3, 15}, {5, 2, 10}, {6, 1, 47}, {7, 1, 60}};
   int n = 7;
   int max_deadline = 5; // Maximum deadline
  
   schedule_jobs(jobs, n, max_deadline);
  
   return 0;
}
