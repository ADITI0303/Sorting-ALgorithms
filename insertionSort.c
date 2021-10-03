#include<stdio.h>
#include<stdlib.h>

int compare(int, int);
void swap(int*, int*);

int main()
{
    int insertionSort[] = {3,6,1,8,4,5};
    int* ptr;
    int n = sizeof(insertionSort)/sizeof(int);
    for(int i=0; i<n-1; i++)
    {
        ptr = (insertionSort+i+1);
        for(int j=i; j>-1; j--)
        {
            int result = compare(insertionSort[j], *ptr);
            if(result == 1)
            {
                swap((insertionSort+j), ptr);
                ptr--;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        printf("%d\n", insertionSort[i]);
    }
    return 0;
}

int compare(int num1, int num2)
{
 if(num1 < num2)
 {
     return -1;
 }
 else if(num1 > num2)
 {
     return 1;
 }
 else return 0;
}

void swap(int* num1, int* num2)
{
 int temp;
 temp = *num1;
 *num1 = *num2;
 *num2 = temp;
}
