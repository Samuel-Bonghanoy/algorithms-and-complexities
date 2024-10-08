#include <stdio.h>

/* Function to sort array using insertion sort */
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

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



void insertionSort2(int arr[], int n)
{
   int x, y, temp;

   for(x = 0; x < n - 1; x++){
    for(y = x + 1; y > 0 ; y--){

        if(arr[y] < arr[y - 1]){
            temp = arr[y - 1];
            arr[y - 1] = arr[y];
            arr[y] = temp;
        }
        
    }
   }
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}


void insertionSort3(int arr[], int size){
    int x,y,temp;

    for(x = 0; x < size; x++){
        for(y = x; y > 0; y--){
            if(arr[y] < arr[y-1]){
                 temp = arr[y - 1];
                arr[y - 1] = arr[y];
                arr[y] = temp;
            }
        }
    }

}

void insertionSort4(int arr[], int size){
    int x,y;

    for(x = 0; x < size; x++){
        for(y = x; y > 0; y--){
            if(arr[y] < arr[y-1]){
                swap(&arr[y], &arr[y-1]);
            }
        }
    }

       for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}


// Driver method
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", n);

    insertionSort4(arr, n);
    // printArray(arr, n);

    return 0;
}
