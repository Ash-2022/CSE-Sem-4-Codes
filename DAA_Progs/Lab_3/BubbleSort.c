#include <stdio.h>

void main()
{
    int n, opCount = 0 , swapCount = 0;
    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value for element %d of the array : ", (i + 1));
        scanf("%d", &arr[i]);
    }

    // Bubble Sort
    int fl = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            opCount++;
            if (arr[j+1] < arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                fl = 1;
                swapCount++;
            }
        }
        if (fl == 0)
        {
            break;
        }
    }

    // After Sorting
    // for (int i = 0; i < n; i++)
    // {
    //     printf("Element %d of the array is : %d\n", (i + 1), arr[i]);
    // }8
    printf("Opcount is : %d %d\n", opCount , swapCount);
}