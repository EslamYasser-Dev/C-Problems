
#include "ext.h"
#define n 10


int main()
{
    int arr[n]={1551,254,321,154,105,685,12158,148,15472,10};


    printf("\n Bubble sort\n");
    bubbleSorting(arr, n);
    printArrays(arr, n);

    printf("\n Selection sort\n");
    seclectionSorting(arr, n);
    printArrays(arr, n);
return 0;
}
