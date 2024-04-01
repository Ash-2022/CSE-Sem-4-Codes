#include<stdio.h>

void TOH(int n, char source , char auxillary , char destination){
    if(n == 0){
        return;
    }
    TOH(n-1 , source , destination , auxillary);
    printf("Moved Disk from %c to %c\n" , source , destination);
    TOH(n-1 , auxillary ,source , destination);
}

void main(){
    int n;
    printf("Number of discs : ");
    scanf("%d" , &n);
    TOH(n , 'A' , 'B', 'C');
}