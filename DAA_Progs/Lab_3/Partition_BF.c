#include <stdio.h>
#include <math.h>

void printPowerSet(int *set, int set_size)
{
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;

    // Arrays to store subsets and their sums
    int subsets[1 << set_size][set_size];
    int subsetSums[1 << set_size];

    int subsetCount = 0; // Variable to keep track of the number of subsets
    int opCount = 0;

    for (counter = 0; counter < pow_set_size; counter++)
    {
        int currentSubsetSum = 0; // Variable to store the sum of the current subset

        for (j = 0; j < set_size; j++)
        {
            
            if (counter & (1 << j))
            {
                // If jth bit is set, include set[j] in the subset
                subsets[subsetCount][j] = set[j];
                currentSubsetSum += set[j];
            }
            else
            {
                // If jth bit is not set, set the element to 0 in the subset
                subsets[subsetCount][j] = 0;
            }
        }

        // Store the sum of the current subset
        subsetSums[subsetCount] = currentSubsetSum;
        subsetCount++;
    }

    // Print the subsets and their sums
    for (int i = 0; i < subsetCount; i++)
    {
        printf("Subset %d: {", i + 1);
        for (int j = 0; j < set_size; j++)
        {
            printf(" %d", subsets[i][j]);
            if (j < set_size - 1 && subsets[i][j + 1] != 0)
            {
                printf(",");
            }
        }
        printf(" } - Sum: %d\n", subsetSums[i]);
    }

    int count = 1;
    int fl = 0;

    // Checking the sums of all the sets in the power set and mathcing it with the corresponding set in the power set
    for (int i = 0; i < (1 << set_size); i++)
    {
        for (int j = i + 1; j < (1 << set_size); j++)
        {
            opCount++;
            if (subsetSums[i] == subsetSums[j])
            {
                printf("Partition %d found. \n The Common Sum is : %d \n The Sets are : \n", (count++), (subsetSums[i]));
                printf("First Set is : \n");
                for (int k = 0; k < set_size; k++)
                {
                    printf(" %d ", subsets[i][k]);
                }
                printf("\n The Second set is : \n");
                for (int k = 0; k < set_size; k++)
                {
                    printf(" %d ", subsets[j][k]);
                }
                printf("\n");
                fl = 1;
            }
        }
    }
    if (fl == 0)
    {
        printf(" No Partitions are possible for the given set \n ");
    }
    printf("Number of partitions found is : %d and the number of subsets is : %d \n", count, subsetCount);
    printf("Opcount is : %d\n" , opCount);
}

int main()
{
    int n;
    printf(" Enter the number of elements int the array : ");
    scanf("%d", &n);
    int set[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        printf(" Enter Element %d ( PLEASE ENTER UNIQUE/DISTINCT ELEMENTS ): ", (i + 1));
        scanf("%d", &set[i]);
        sum += set[i];
    }
    int set_size = sizeof(set) / sizeof(set[0]);
    printPowerSet(set, set_size);
    printf("\nMax sum possible is : %d", sum);
    return 0;
}