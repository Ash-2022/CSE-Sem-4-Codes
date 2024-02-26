#include <stdio.h>
#include <math.h>

int isPrime(int n, int *opCount)
{
    int i, count = 0;
    for (i = 2; i < sqrt(n); i++)
    {
        *opCount += 1;
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void main()
{
    int gcd = 1, m, n, i = 2, min, max, opCount = 0;
    printf("Enter the 2 numbers ");
    scanf("%d %d", &m, &n);
    min = m < n ? m : n;
    max = m > n ? m : n;
    do
    {
        opCount++;
        if ((min % i == 0) && (max % i == 0))
        {
            if (isPrime(i, &opCount))
            {
                min = min / i;
                max = max / i;
                gcd *= i;
                i--;
            }
        }
        i++;
    } while (i <= min);
    printf("The GCD of %d and %d is : %d\nOpCount is %d\n", m, n, gcd, opCount);
}