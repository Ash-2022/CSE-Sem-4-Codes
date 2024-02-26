#include <stdio.h>

void main() {
    int m, n, min, i, gcd, opCount = 0;
    printf("Enter both numbers ");
    scanf("%d %d",&m, &n);
    min = m < n ? m : n;
    for (i = min; i >= 1; i--) {
        opCount++;
        if (m % i == 0 && n % i == 0) {
            gcd = i;
            break;
        }
    }
    printf("GCD of %d and %d is %d\nOpcount is: %d\n", m, n, gcd, opCount); 
}