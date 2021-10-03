//C Program to sort the array using merge sort using pointers in C

#include<stdio.h>
#include<stdlib.h>

void merge(int*, int*, int*);
void mergeSort(int*, int*);
void swap(int*, int*);

int main()
{
//    int mSort[] = {45, 7, 30, 67, 23, 60};
    int mSort[] = {4, 3, 7, 98, 67, 2, 60, 1, 87};
    int* startIndex = mSort;
    int* endIndex = mSort+((sizeof(mSort)/sizeof(int))-1);
    int n = sizeof(mSort)/sizeof(int);
    mergeSort(startIndex, endIndex);
    for(int i=0; i<n; i++)
    {
        printf("%d\n", mSort[i]);
    }
    return 0;
}

void merge(int* firstArray, int* secondArrayStart, int* secondArrayEnd)
{
    while(firstArray != secondArrayStart)
    {
        if(*firstArray > *secondArrayStart)
        {
            swap(firstArray, secondArrayStart);
            int* temp = secondArrayStart;
            while(temp!=secondArrayEnd)
            {
                if(*temp>*(temp+1))
                {
                    swap(temp, (temp+1));
                }
                else{break;}
                temp++;

            }
        }
        firstArray++;
    }
}

void swap(int* firstPtr, int* secondPtr)
{
    int temp = *secondPtr;
    *secondPtr = *firstPtr;
    *firstPtr = temp;
}

void mergeSort(int* startIndex, int* endIndex)
{
    if(startIndex==endIndex)
    {
        return;
    }
    else
    {
        int* pivot = startIndex+((endIndex - startIndex)/2);
        mergeSort(startIndex, pivot);
        mergeSort(pivot+1, endIndex);
        merge(startIndex, pivot+1, endIndex);
    }
}
