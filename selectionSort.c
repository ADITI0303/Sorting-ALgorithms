//C program to sort the array using selection sort

#include<stdio.h>
#include<stdlib.h>

int compare(int, int);
void swap(int*, int*);

int main()
{
 int selectionSort[] = {3,6,1,8,4,5};
 int* ptr;
 int n = sizeof(selectionSort)/sizeof(int);
 for(int i=0; i<n-1; i++)
 {
     ptr = (selectionSort+i+1);
     for(int j=0; j<n-i-1; j++)
     {
         int result = compare(selectionSort[i], *ptr);
         if(result == 1)
         {
             swap((selectionSort+i), ptr);
         }
         ptr++;
     }
 }
 for(int i=0; i<n; i++)
 {
     printf("%d\n", selectionSort[i]);
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
