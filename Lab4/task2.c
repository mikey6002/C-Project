#include <stdio.h>

// SortAndFind() that take array of int and sort it and return index of x element in side index.
int SortAndFind(int arr[], int n, int x)
{
    // use bubble sort to sort the ary
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // if arr[j] is greater than arr[j+1] swap that element
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // find x in array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            // if found return i
            return i;
        }
    }
    // else return -1
    return -1;
}

int main()
{
    // declare n
    int n;
    // take input form user for n
    printf("Enter size of array: ");
    scanf("%d", &n);
    // declare arrya of size n
    int array[n];
    printf("Enter array element: ");
    // take input for n int
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    // declare x
    int x;
    // take input for x
    printf("Enter element to find in array: ");
    scanf("%d", &x);
    // call to SortAndFind function
    int index = SortAndFind(array, n, x);
    // print not found for not found
    if (index == -1)
    {
        printf("Element not found!\n");
    }
    // else print foudn index
    else
    {
        printf("Element found at index %d!\n", index);
    }

    // print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}