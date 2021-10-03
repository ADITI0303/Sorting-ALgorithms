//C Program to Quick Sort an array using pointers
#include<stdio.h>
#include<stdlib.h>

int* partition(int*,int*);
void quickSort(int*, int*);
void swapQuick(int*, int*);

int main()
{
    int qSort[] = {45, 7, 3, 67, 23, 60, 9};
    int* startIndex = qSort;
    int* endIndex = qSort+((sizeof(qSort)/sizeof(int))-1);
    int n = sizeof(qSort)/sizeof(int);
    quickSort(startIndex, endIndex);
    for(int i=0; i<n; i++)
    {
        printf("%d\n", qSort[i]);
    }
    return 0;
}

int* partition(int* nextElement, int* pivot)
{
    int *max = nextElement;
    while(nextElement != pivot)
    {
        if(*nextElement > *pivot)
        {
            max = nextElement;
            nextElement++;
            break;
        }
        nextElement++;
    }
    int i = 0;
    while(nextElement != pivot)
    {
        if(*nextElement < *pivot)
        {
            swapQuick(nextElement, max);
            max = nextElement;
        }
        nextElement++;
        i++;
    }
    swapQuick(max, pivot);
    pivot = max;
    return pivot;
}

void swapQuick(int* firstPtr, int* secondPtr)
{
    int temp = *secondPtr;
    *secondPtr = *firstPtr;
    *firstPtr = temp;
}

void quickSort(int* startIndex, int* endIndex)
{
    if((endIndex-startIndex)<1)
    {
        return;
    }
    else
    {
        int* pivot = partition(startIndex, endIndex);
        quickSort(startIndex, pivot-1);
        quickSort(pivot+1, endIndex);
    }

}
