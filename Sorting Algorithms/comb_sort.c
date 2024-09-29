/*
 * C Program to Perform Comb Sort on Array of Integers
 */
#include <stdio.h>
#include <stdlib.h>
 
/*Function to find the new gap between the elements*/
int newgap(int gap)
{
    gap = (gap * 10) / 13;
    if (gap == 9 || gap == 10)
        gap = 11;
    if (gap < 1)
        gap = 1;
    return gap;
}
 
/*Function to implement the combsort*/
void combsort(int a[], int size)
{
    
}
int main ()
{
    int n, i;
    int arr[] = { 12, 11, 13, 5, 6, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);
    combsort(arr, size);
    printf("Sorted list:\n");        // Display the sorted array
    for(i = 0;i < size;i++)
    {
        printf("%d ", (arr[i]));
    }
    return 0;
}