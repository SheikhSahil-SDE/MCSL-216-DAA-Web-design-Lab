// Q3 What is an optimal binary tree and Huffman code for the following set of frequencies? 
//    Find out the average number of bits required per character. Show the complete steps.
                            // A:15 B:25 C:5 D:7 E:10 F:13 G:9


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Structure for tree nodes
typedef struct Node {
   char letter; // '\0' for non-leaf nodes
   int freq;
   struct Node *left, *right;
} Node;


// Structure for min-heap
typedef struct MinHeap {
   int size;
   int capacity;
   Node **array;
} MinHeap;


// Create a new node
Node* newNode(char letter, int freq) {
   Node* node = (Node*)malloc(sizeof(Node));
   node->letter = letter;
   node->freq = freq;
   node->left = node->right = NULL;
   return node;
}


// Create a min-heap
MinHeap* createMinHeap(int capacity) {
   MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
   heap->size = 0;
   heap->capacity = capacity;
   heap->array = (Node**)malloc(capacity * sizeof(Node*));
   return heap;
}


// Swap two nodes
void swapNodes(Node **a, Node **b) {
   Node *temp = *a;
   *a = *b;
   *b = temp;
}


// Heapify at index i
void minHeapify(MinHeap* heap, int i) {
   int smallest = i;
   int left = 2 * i + 1;
   int right = 2 * i + 2;
   if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
       smallest = left;
   if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
       smallest = right;
   if (smallest != i) {
       swapNodes(&heap->array[i], &heap->array[smallest]);
       minHeapify(heap, smallest);
   }
}


// Extract minimum node
Node* extractMin(MinHeap* heap) {
   if (heap->size == 0) return NULL;
   Node* min = heap->array[0];
   heap->array[0] = heap->array[heap->size - 1];
   heap->size--;
   minHeapify(heap, 0);
   return min;
}


// Insert node into heap
void insertMinHeap(MinHeap* heap, Node* node) {
   heap->size++;
   int i = heap->size - 1;
   heap->array[i] = node;
   while (i && heap->array[i]->freq < heap->array[(i-1)/2]->freq) {
       swapNodes(&heap->array[i], &heap->array[(i-1)/2]);
       i = (i-1)/2;
   }
}


// Build min-heap from array
void buildMinHeap(MinHeap* heap) {
   for (int i = (heap->size - 2) / 2; i >= 0; i--)
       minHeapify(heap, i);
}


// Generate codes by traversing tree
void generateCodes(Node* root, char *code, int len, char codes[][20], int lengths[], char letters[], int n) {
   if (!root) return;
   if (root->letter != '\0') {
       for (int i = 0; i < n; i++) {
           if (letters[i] == root->letter) {
               code[len] = '\0';
               strcpy(codes[i], code);
               lengths[i] = len;
               break;
           }
       }
   }
   char left[20], right[20];
   strcpy(left, code);
   strcpy(right, code);
   left[len] = '0';
   right[len] = '1';
   generateCodes(root->left, left, len + 1, codes, lengths, letters, n);
   generateCodes(root->right, right, len + 1, codes, lengths, letters, n);
}


// Huffman coding algorithm
void huffmanCoding(char letters[], int freq[], int n) {
   // Create min-heap
   MinHeap* heap = createMinHeap(n);
   for (int i = 0; i < n; i++) {
       heap->array[i] = newNode(letters[i], freq[i]);
       heap->size++;
   }
   buildMinHeap(heap);
  
   // Build Huffman tree
   while (heap->size > 1) {
       Node *left = extractMin(heap);
       Node *right = extractMin(heap);
       Node *parent = newNode('\0', left->freq + right->freq);
       parent->left = left;
       parent->right = right;
       insertMinHeap(heap, parent);
   }
  
   // Generate codes
   Node* root = extractMin(heap);
   char codes[n][20];
   int lengths[n];
   char code[20] = "";
   generateCodes(root, code, 0, codes, lengths, letters, n);
  
   // Calculate expected length
   int total_freq = 0, weighted_sum = 0;
   for (int i = 0; i < n; i++) {
       total_freq += freq[i];
       weighted_sum += freq[i] * lengths[i];
   }
  
   // Print results
   printf("Q3: Huffman Coding\n");
   printf("Letter | Frequency | Code | Length\n");
   printf("-------|-----------|------|-------\n");
   for (int i = 0; i < n; i++) {
       printf("%c      | %d        | %s | %d\n", letters[i], freq[i], codes[i], lengths[i]);
   }
   printf("\nAverage Number of Bits per Character: %.4f bits\n", (double)weighted_sum / total_freq);
  
   // Cleanup
   free(heap->array);
   free(heap);
   // Note: Tree nodes not freed for simplicity
}


int main() {
   char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
   int freq[] = {15, 25, 5, 7, 10, 13, 9};
   int n = 7;
  
   huffmanCoding(letters, freq, n);
  
   return 0;
}
                            
