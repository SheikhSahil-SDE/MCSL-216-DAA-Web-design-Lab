// Q2.Implement the task scheduling algorithm on your system to minimize the total amount 
// of Time spent in the system for the following problem:

// 		Job 		Service Time
// 		 1			5
// 	     2			10
// 		 3			7
// 		 4			8

#include <stdio.h>
#include <stdlib.h>


// Structure to hold job details
typedef struct {
   int id; // Job ID (1-based)
   int service_time;
} Job;


// Comparison function for qsort (ascending order of service time)
int compare(const void *a, const void *b) {
   Job *jobA = (Job *)a;
   Job *jobB = (Job *)b;
   return jobA->service_time - jobB->service_time;
}


double schedule_jobs(Job jobs[], int n) {
   // Sort jobs by service time
   qsort(jobs, n, sizeof(Job), compare);
  
   double total_time = 0;
   int current_time = 0;
  
   // Calculate completion times
   for (int i = 0; i < n; i++) {
       current_time += jobs[i].service_time;
       total_time += current_time;
   }
  
   return total_time;
}


int main() {
   Job jobs[] = {{1, 5}, {2, 10}, {3, 7}, {4, 8}};
   int n = 4;
  
   double total_time = schedule_jobs(jobs, n);
  
   printf("Q2:\n");
   printf("Optimal Schedule: ");
   for (int i = 0; i < n; i++) {
       printf("J%d", jobs[i].id);
       if (i < n - 1) printf(", ");
   }
   printf("\nTotal Time Spent in System: %.0f\n", total_time);
  
   return 0;
}

