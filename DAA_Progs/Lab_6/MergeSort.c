#include <stdio.h>
#include <stdlib.h>

int opCount = 0;

void merge(int * B , int B_size ,  int * C , int C_size ,int *A , int A_size){
    int i = 0 , j = 0, k = 0;
    while ((i < B_size) && (j < C_size)){
        if(B[i] <= C[j]){
            A[k] = B[i];
            i++;
        }
        else{
            A[k] = C[j];
            j++;
        }
        k++;
    }
    if(i == B_size){
        while((j < C_size) && (k < A_size)){
            A[k] = C[j];
            k++;
            j++;
        }
    }
    else{
        while((i < C_size) && (k < A_size)){
            A[k] = B[i];
            k++;
            i++;
        }
    }
}

void mergeSort(int*arr , int arr_size){
    int B_size = arr_size / 2;
    int C_size = arr_size - B_size;
    int * B = (int*) calloc(B_size , sizeof(int));
    int * C = (int*) calloc(C_size , sizeof(int));
    if(arr_size > 1){
        opCount++;
        for(int i = 0; i < B_size; i++){
            B[i] = arr[i];
        }
        for(int i = B_size; i < arr_size;i++){
            C[i - B_size] = arr[i];
        }
        mergeSort(B , B_size);
        mergeSort(C , C_size);
        merge(B , B_size , C , C_size , arr , arr_size);
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
    mergeSort(arr , n);
    for(int i = 0; i < n; i++){
        printf("Element %d of the sorted array is : %d \n" , (i+1) , arr[i]);
    }
    printf("\n OpCount : %d\n" , opCount);
}