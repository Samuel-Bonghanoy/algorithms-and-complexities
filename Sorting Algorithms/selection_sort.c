// C program for implementation of selection sort
#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

void selectionSort2(int arr[], int n){
    int x, y, min;

    for(x = 0; x < n; x++){
        min = x;
        for(y = x; y < n; y++){
            if(arr[y] < arr[min]){
                min = y;
            }
        }
        if(min != x) swap(&arr[min], &arr[x]);
    }

}

void selectionSort3(int arr[], int size){
    int x,y,min;

    for(x = 0; x < size; x++){
        min = x;

        for(y = x; y < size; y++){
            if(arr[y] < arr[min]){
                min = y;
            }
        }

        if(min != x) swap(&arr[min], &arr[x]);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort3(arr, n);
    printf("Sorted array2: \n");
    printArray(arr, n);
    return 0;
}