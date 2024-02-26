#include <stdio.h>
#include <string.h>

void main() {
    char text[50], pattern[50];
    int i,idx, flag = 0 , opCount = 0;
    printf("Enter Text : ");
    scanf("%s",text);
    printf("Enter Pattern : ");
    scanf("%s",pattern);
    for (i=0; i < strlen(text) - strlen(pattern) + 1; i++) {
        for (idx = 0; idx < strlen(pattern); idx++) {
            opCount++;
            if (pattern[idx] != text[i+idx])
                break;
        }
        if (idx == strlen(pattern))
            break;
    }
    if (idx == strlen(pattern))
        printf("Substring is at index %d. \n",i);
    else
        printf("TExt does not have the Pattern \n");
    printf("Opcount is : %d\n", opCount);
}