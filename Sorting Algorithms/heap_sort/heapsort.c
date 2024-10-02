#include <stdio.h>
#include <stdlib.h>

// * MACROS HERE
#define MAX 20
#define DNE -100


// * FUNCTION DEFINITIONS HERE
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int size, int root) {
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    int largest = root;
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != root) {
        swap(&arr[largest], &arr[root]);
        heapify(arr, size, largest);
    }
}


void heapify2(int arr[], int size, int root){
  int left = root * 2 + 1;
  int right = root * 2 + 2;
  int largest = root;

  if(left < size && arr[largest] < arr[left]) {
    largest = left;
  }

  if(right < size && arr[largest] < arr[right]) {
    largest = right;
  }

  if(largest != root) {
    swap(&arr[largest], &arr[root]);
    heapify2(arr, size, largest);
  }
}

void heapify3(int arr[], int size, int root){
  int left = root * 2 + 2;
  int right = root * 2 + 1;
  int largest = root;

  if(left < size && arr[left] > arr[largest]){
    largest = left;
  }

  if(right < size && arr[right] > arr[largest]){
    largest = right;
  }

  if(largest != root){
    swap(&arr[largest], &arr[root]);
    heapify3(arr, size, largest);
  }
}

void heapsort3(int arr[], int size){
  int x;

  for(x = size/2-1; x > size; x--){
    heapify(arr, size,x);
  }

  for(x = size - 1; x >= 0; x--){
    swap(&arr[0], &arr[x]);
    heapify(arr, x, 0);
  }
}

void heapsort2(int arr[], int size){
  int x;

  for(x = size / 2 - 1; x >= 0; x --){
    heapify(arr,size,x);
  }

  for(x = size - 1; x >= 0; x--){
    swap(&arr[x], &arr[0]);
    heapify(arr, x, 0);
  }
}

void heapSort(int arr[], int size) {
    for (int x = size / 2 - 1; x >= 0; x--) {
        heapify(arr, size, x);
    }
    for (int x = size - 1; x >= 0; x--) {
        swap(&arr[x], &arr[0]);
        heapify(arr, x, 0);
    }
}


int main(void) 
{   
    int arr [9]= {9,2,18,23,5,1,8,27,7};
    pQueue q;
    q.heap[0] = 3;
    q.heap[1] = 10;
    q.heap[2] = 2;
    q.heap[3] = 39;
    q.heap[4] = 9;
    q.heap[5] = 15;
    q.heap[6] = 23;
    q.heap[7] = 4;
    q.heap[8] = 1;
    q.heap[9] = 20;
    q.heap[10] = 7;
    q.heap[11] = 15;
    q.heap[12] = 0;
    q.lastIndex = 12;

    // Display(q);
    // Initialize(&q);
    // Insert(3, &q);
    // Insert(10, &q);
    // Insert(2, &q);
    // Insert(39, &q);
    // Insert(9, &q);
    // Insert(15, &q);
    // Insert(23, &q);
    // Insert(4, &q);
    // Insert(1, &q);
    // Insert(20, &q);
    // Insert(7, &q);
    // Insert(15, &q);
    // Insert(0, &q);
    // DeleteMin(&q);
    // DeleteMin(&q);
    // DeleteMin(&q);
    // DeleteMin(&q);
    // DeleteMin(&q);
    // DeleteMin(&q);
    // Display(q);
    heapSort(arr, 9);
    for(int x = 0; x < 9; x ++) {
        printf("%d ", arr[x]);
    }
    return 0;
}
