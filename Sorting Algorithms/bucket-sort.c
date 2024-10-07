#include <stdio.h>
#include <stdlib.h>

#define MAX 14

typedef struct {
 int elem[MAX];
 int count;
} ARRAY;

typedef struct Node {
 int data;
 struct Node *next;
} *LL;
void initializeBucket(LL *lp) {
 *lp = NULL;
}

void insertSortedIntoBucket(LL *lp, int data) {
 LL *trav;

 for (trav = lp; *trav != NULL && (*trav)->data <= data; trav = &(*trav)->next) {

 LL temp = malloc(sizeof(struct Node));
 if (temp != NULL) {
 temp->data = data;
 temp->next = *trav;
 *trav = temp;
 }
}

int removeFirstFromBucket(LL *lp) {
 LL temp = *lp;

 *lp = temp->next;
 int data = temp->data;
 free(temp);

 return data;
}

void bucketSort(ARRAY *arr) {
 int i, j, min, max;

 // Get range of elements
 for (i = 1, min = arr->elem[0], max = arr->elem[0]; i < arr->count; i++) {
 if (arr->elem[i] < min) {
 min = arr->elem[i];
 }

 if (arr->elem[i] > max) {
 max = arr->elem[i];
 }
 }

 // Number of buckets is range / size of input if range > size
 // else number of buckets is size of input
 int bucketNum = (max - min) < arr->count ? arr->count : (max - min) / arr->count
 LL *buckets = (LL*)malloc(bucketNum * sizeof(LL));

 for (i = 0; i < bucketNum; i++) {
 initializeBucket(buckets + i);
 }

 // Insert elements into bucket via insert sorted
 for (i = 0; i < arr->count; i++) {
 int bucket = (arr->elem[i] - min) * bucketNum / (max - min + 1);
 insertSortedIntoBucket(buckets + bucket, arr->elem[i]);
 }

 // Concatenate buckets
 for (i = 0; i < arr->count;) {
 for (j = 0; j < bucketNum && buckets[j] != NULL; j++) {
 int num = removeFirstFromBucket(buckets + j);
 arr->elem[i++] = num;
 }
 }
}
