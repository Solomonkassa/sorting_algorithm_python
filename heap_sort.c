#include <stdio.h>

/**
 *  Author: Solomon Kassa
 *  heapify - Create max heap
 * 
 *  @array: An array of integer
 *  @n: Size of an array
 *  i: Creating heap
 */
 #define MAX_SIZE 1024
 
void heapify(int *array, size_t n, int i)
{
    
    int tmp, large = i;
    // Left child 
    int l = 2 * i + 1;
    // Right child
    int r = 2 * i + 2;
    
    if (l < n && array[l] > array[large])
    {
        large = l;// If lift child greaterthan larger set index 
    }
    
    if (r < n && array[r] > array[large])
    {
        large = r;// If lift child greaterthan larger set index 
    }
    
    if (large != i)
    {
        // Swap 
        tmp = array[i];
        array[i] = array[large];
        array[large] = tmp;
        // recurssion
        heapify(array, n, large);
    }
}

/**
 *  heapsort - sort heap function take two parameters
 * 
 *  @array: An array of integer
 *  @size: Size of an array
 */

void heapsort(int *array, size_t size)
{
    int i, tmp;
    
    // build heap
    for (i = size / 2 - 1; i >= 0; i--)
    {
        heapify(array, size, i);
    }
    
     // extract elements from the heap in decreasing order
     for (i = size - 1; i >= 0; i--)
     {
        // swap the root (largest element) with the last element in the heap
         tmp = array[0];
         array[0] = array[i];
         array[i] = tmp;
         
         // restore the heap property in the remaining heap
         heapify(array, i, 0);
     }
}

/**
 *  printArray - print a given array
 *  
 *  @array: An array of integer
 *  @size: Size of an array
 */
 
void printArray(int *array, size_t size)
{
    size_t i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int data[MAX_SIZE];
    int n = 0, input;

    while (n < MAX_SIZE)
    {
        printf("Enter a number (or -1 to sort): ");
        scanf("%d", &input);

        if (input == -1)
        {
            printf("Before sorting:\n");
            printArray(data, n);

            heapsort(data, n);

            printf("After sorting:\n");
            printArray(data, n);

            break;
        }

        data[n] = input;
        n++;
    }
    
    return 0;
}
