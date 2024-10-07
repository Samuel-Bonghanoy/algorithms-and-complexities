 #include <stdio.h>


void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void gnomeSort(int arr[], int n) 
{ 
    int index = 0; 
  
    while (index < n) { 
        if (index == 0) 
            index++; 
        if (arr[index] >= arr[index - 1]) 
            index++; 
        else { 
            swap(&arr[index], &arr[index - 1]); 
            index--; 
        } 
    } 
    return; 
} 


/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}


// Driver method
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", n);
  gnomeSort(arr, n);
    // printArray(arr, n);

    return 0;
}
