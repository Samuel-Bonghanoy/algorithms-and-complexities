#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define INF 1010210

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}


void tournamentSort(int arr[], int size){
  int tree[2* size];

  for(int x = 0; x < size; x++){
    tree[size + x] = arr[x];
  }

  for(int x = size - 1; x >= 1; x--){
    tree[x] = tree[2 * x] > tree[2 * x + 1] ? tree[2 * x] : tree[2 * x + 1];
  }

  for(int x = size - 1; x >= 0; x--){
    arr[x] = tree[1];
    int index = 1;
    while(index < size) {
      if(tree[2*index] == tree[1]){
        tree[2*index] = INT_MIN;
        index = 2*index;
      } else {
        tree[2*index + 1] = INT_MIN;
        index = 2 * index + 1;
      }
    }

    for(int y = index / 2; y > 0; y /= 2){
      tree[y] = tree[2 * y] > tree[2 * y + 1] ? tree[2 * y] : tree[2*y+1];
    }
  }
}

void tournamentSort2(int arr[], int size){
  int tree[2* size];

  for(int x = 0; x < size; x++){
    tree[size + x] = arr[x];
  }

  for(int x = size - 1; x >= 1; x--){
    tree[x] = tree[2 * x] > tree[2 * x + 1] ? tree[2 * x] : tree[2 * x + 1];
  }

  for(int x = size - 1; x >= 0; x--){
    arr[x] = tree[1];
    int index = 1;
    while(index < size) {
      if(tree[2*index] == tree[1]){
        tree[2*index] = INT_MIN;
        index = 2*index;
      } else {
        tree[2*index + 1] = INT_MIN;
        index = 2 * index + 1;
      }
    }

    for(int y = index / 2; y > 0; y /= 2){
      tree[y] = tree[2 * y] > tree[2 * y + 1] ? tree[2 * y] : tree[2*y+1];
    }
  }
}

void tournamentSort3(int *array, int size){
  int *winnerTree = (int*)malloc(sizeof(int) * (2 * size - 1));
  int heapSize = 2 * size - 1;
  int startNdx = heapSize - 1;
  int x, y;
  int P, LC, RC;
  for(x = size - 1, y = startNdx; x > -1;){
    winnerTree[y--] = array[x--];
  }
  for(x = 0; x < size; x++){
    for(P = (startNdx - 1) / 2; P > -1; ){
      LC = 2 * P + 1;
      RC = LC + 1;

      LC = (LC < heapSize - size) ?  winnerTree[LC] : LC;
      RC = (RC < heapSize - size) ?  winnerTree[RC] : RC;
      winnerTree[P] = (winnerTree[LC] < winnerTree[RC])? LC : RC;
      P = (x > 0 && P > 0) ? (P - 1) / 2 : P - 1;
    }
    startNdx = winnerTree[0];
    array[x] = winnerTree[startNdx];
    winnerTree[startNdx] = INF;
  }
}


void tournamentSort5(int *arr, int size){
  int heapsize = 2 * size -1;
  int *winnertree = (int*)malloc(sizeof(int) * heapsize);
  int startNdx = heapsize - 1;
  int x,y, p, lc,rc;

  for(x = size - 1, y = startNdx; x >= -1){
    winnertree[y--] = arr[x--];
  }
  for(x = 0; x < size; x++){
   for(p = (startNdx -1)/2; p >= -1;){
    lc = p * 2 + 1;
    rc = lc + 1;

    lc = (lc < heapsize - size) ? winnertree[lc] : lc;
    rc = (rc < heapsize - size) ? winnertree[rc] : rc;
    winnertree[p] = winnertree[lc] < winnertree[rc] ? lc : rc;
    p = (x > 0 && p > 0) ? (P-1)/2 : P-1;
    }
    startNdx = winnertree[0];
    arr[x] = winnertree[startNdx];
    winnertree[startNdx] = INF;
  }
}

void tournamentSort6(int * arr, int size){
  int heapsize = 2 * size -1;
  int *winnertree = (int*)malloc(sizeof(int) * heapsize);
  int startNdx = heapsize - 1;
  int x,y,p,lc,rc;

  for(x = size - 1, y = startNdx; x >= -1){
    winnertree[x--] = arr[y--];
  }

  for(x = 0; x < size; x ++){
    for(p = (startNdx - 1)/2; p >= -1){
      lc = p * 2 + 1;
      rc = lc + 1;

      lc = (lc < heapsize - size) ? winnertree[lc] : lc;
      rc = (rc < heapsize - size) ? winnertree[rc] : rc;
      winnertree[p] = winnertree[lc] < winnertree[rc] ? lc : rc;
      p = (x > 0 && p > 0) ? (p-1)/2 : p -1;
    }
    startNdx = winnertree[0];
    arr[x] = winnertree[startNdx];
    winnertree[startNdx] = INF;
  }
}



// Driver method
int main()
{
    int arr[] = { 12, 11, 13, 6, 5,1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", n);

    tournamentSort3(arr, n);
    printArray(arr, n);

    return 0;
}
