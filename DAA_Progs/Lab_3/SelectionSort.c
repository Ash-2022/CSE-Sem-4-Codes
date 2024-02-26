#include <stdio.h>

void main()
{
    int n, opCount = 0;
    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value for element %d of the array : ", (i + 1));
        scanf("%d", &arr[i]);
    }

    // Selection Sort
    int min_idx = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            opCount++;
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        min_idx = i + 1;
    }

    //After Sorting
    for(int i = 0; i < n;i++){
        printf("Element %d of the array is : %d\n" , (i+1) , arr[i]);
    }
    printf("Opcount is : %d\n", opCount);
}