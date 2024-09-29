// Optimized implementation of Bubble sort
#include <stdbool.h>
#include <stdio.h>

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}

void bubbleSort2(int arr[], int n) {
    int x,y;

    for(x = 0; x < n; x++) {
        for(y = 0; y < n - x; y++) {
            if(arr[y] > arr[y+1]){
                swap(&arr[y], &arr[y + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}


void bubbleSort3(int arr[], int size){
    int x, y;

    for(x = 0; x < size; x++){
        for(y = 0; y < size - x; y++){
            if(arr[y] > arr[y+1]){
                swap(&arr[y], &arr[y+1]);
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

// Driver program to test above functions
int main()
{
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Sorted array: \n");
    bubbleSort2(arr, n);
    // printArray(arr, n);
    return 0;
}