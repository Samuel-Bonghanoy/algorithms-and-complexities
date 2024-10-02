#include <stdio.h>
#include <limits.h>


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




// Driver method
int main()
{
    int arr[] = { 12, 11, 13, 6, 5,1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", n);

    tournamentSort(arr, n);
    printArray(arr, n);

    return 0;
}
