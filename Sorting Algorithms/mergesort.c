#include <stdio.h>

#define MAX 12

typedef struct {
 int elem[MAX];
 int count;
} ARRAY;
void mergeSort(ARRAY *arr, int low, int high) {
 if (low >= high) {
 return;
 }

 int middle = (low + high) / 2;
 mergeSort(arr, low, middle);
 mergeSort(arr, middle + 1, high);

 merge(arr, low, middle, high);
}

void merge(ARRAY *arr, int low, int middle, int high) {
 int leftLen = middle - low + 1;
 int rightLen = high - middle;
 int i, j, k;

 int leftArr[leftLen], rightArr[rightLen];

 // Populate temporary arrays
 for (i = 0; i < leftLen; i++) {
 leftArr[i] = arr->elem[low + i];
 }

 for (i = 0; i < rightLen; i++) {
 rightArr[i] = arr->elem[middle + 1 + i];
 }

 for (i = 0, j = 0, k = low; i < leftLen && j < rightLen; k++) {
 if (leftArr[i] <= rightArr[j]) {
 arr->elem[k] = leftArr[i];
 i++;
 } else {
 arr->elem[k] = rightArr[j];
 j++;
 }
 }

 for (; i < leftLen; i++, k++) {
 arr->elem[k] = leftArr[i];
 }

 for (; j < rightLen; j++, k++) {
 arr->elem[k] = rightArr[j];

 }
}
