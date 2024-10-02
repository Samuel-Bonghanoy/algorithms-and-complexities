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

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

 
/*Function to implement the combsort*/
void combsort(int arr[], int size)
{
    int x;

    int pairCount, hasSwapped = 1;

      for (int gap = size / 1.3; gap >= 1 ; gap /= 1.3){
        hasSwapped = 0;

        for (int x = 0; x < size - gap; x++)
        {
          if (arr[x] > arr[x + gap])
          {
            swap(&arr[x], &arr[x + gap]);
            hasSwapped = 1;
          }
        }
    }

}

void combsort2(int arr[], int size)
{
   int x, gap;

  for(gap = size/1.3; gap >= 1; gap/=1.3){
    for(x = 0; x < size - gap; x++){
      if(arr[x] > arr[x+gap]){
        swap(&arr[x], &arr[x+gap]);
      }
    }
  }
}

void combSort4(int arr[], int size){
  int gap,x;

  for(gap = size/1.3; gap > 0; gap/=1.3){
    for(x = 0; x < size - gap; x++){
      if(arr[x] > arr[x+gap]){
        swap(&arr[x], &arr[x+gap]);
      }
    }
  }
}


int main ()
{
    int n, i;
    int arr[] = { 12, 11, 13, 5, 6, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);
    combSort4(arr, size);
    printf("Sorted list:\n");        // Display the sorted array
    for(i = 0;i < size;i++)
    {
        printf("%d ", (arr[i]));
    }
    return 0;
}