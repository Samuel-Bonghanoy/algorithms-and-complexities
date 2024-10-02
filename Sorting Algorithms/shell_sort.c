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

int shellSort(int arr[], int n)
{
    int i,j,gap;
  
    for (gap = n/2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i += 1)
        {
            int temp = arr[i];
                 
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
           
            arr[j] = temp;
        }
    }
    return 0;
}


int shellSort2(int arr[], int size){
    int x,y,gap,temp;

    for(gap = size/2; gap > 0; gap /=2){
        for(x = gap; x < size; x++){
            temp = arr[x];

            for(y = x; y >= gap && arr[y - gap] > temp; y -= gap){
                arr[y] = arr[y - gap];
            }

            arr[y] = temp;
        }
    }
}

int shellSort3(int arr[], int size){
    int x,y,gap,temp;

    for(gap = size/2; gap > 0; gap/=2){
        for(x = gap; x < size; x++){
            temp = arr[x];

            for(y = x; y >= gap && arr[y - gap] > temp; y-= gap){
                arr[y] = arr[y - gap];
            }

            arr[y] = temp;
        }
    }
}


// Driver method
int main()
{
    int arr[] = { 5, 11, 12, 5, 6, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", n);

    shellSort3(arr, n);
    printArray(arr, n);

    return 0;
}
