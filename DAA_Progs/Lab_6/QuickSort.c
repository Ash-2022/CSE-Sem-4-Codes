#include <stdio.h>
#include <stdlib.h>

int opCount = 0;

void swap(int *x , int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int WhorePartition(int * A , int l , int r){
    int p = A[l];
    int i = l , j = r+1;
    do{
        do{
            i++;
        }while(A[i]<p);
        do{
            j--;
        }while(A[j]>p);
        swap(&A[i] , &A[j]);
    }
    while(i < j);
    swap(&A[i] , &A[j]);
    swap(&A[l] , &A[j]);
    return j;
}

void quickSort(int * A , int l , int r){
    if(l < r){
        opCount++;
        int s = WhorePartition(A , l , r);
        quickSort(A , l , s-1);
        quickSort(A , s+1 , r);
    }
}

void main(){
    int n;
    printf("Enter the number of elements in the array : ");
    scanf("%d" , &n);
    int * arr = (int*) calloc(n , sizeof(int));
    for(int i = 0; i<n; i++){
        printf("Enter the element %d of the array :" ,  (i+1));
        scanf("%d" , &arr[i]);
    }
    quickSort(arr , 0 , n-1);
    for(int i = 0; i < n; i++){
        printf("Element %d of the sorted array is : %d \n" , (i+1) , arr[i]);
    }
    printf("\n OpCount : %d\n" , opCount);
}

