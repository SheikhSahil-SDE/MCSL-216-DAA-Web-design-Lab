// Q1 Apply Huffman’s algorithm to construct an optimal binary prefix code for the letters and their frequencies in the following table. 

                        // Letters		A 	B	I	M	S	X	Z
                        // Frequency		10	7	15	8	10	5	2

// Show the complete steps.


#include <stdio.h>


int main() {
   char letters[] = {'A', 'B', 'I', 'M', 'S', 'X', 'Z'};
   int freq[] = {10, 7, 15, 8, 10, 5, 2};
   char *codes[] = {"111", "001", "10", "110", "00", "0001", "0000"};
   int lengths[] = {3, 3, 2, 3, 2, 4, 4};
   int n = 7;
   int total_freq = 57;
   int weighted_sum = 0;
  
   printf("Q1: Huffman Coding\n");
   printf("Letter | Frequency | Code | Length\n");
   printf("-------|-----------|------|-------\n");
   for (int i = 0; i < n; i++) {
       printf("%c      | %d        | %s | %d\n", letters[i], freq[i], codes[i], lengths[i]);
       weighted_sum += freq[i] * lengths[i];
   }
   printf("\nExpected Codeword Length: %.4f bits/symbol\n", (double)weighted_sum / total_freq);
  
   return 0;
}
