#include <stdio.h>
#include <stdlib.h>

void swap(int* x , int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void display( int *arr , int n){
    for(int i = 0; i<n; i++){
        printf(" %d " , arr[i]);
    }
    printf("\n");
}

unsigned int factorial(int n){
    if (n == 1){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

void permute(int arr[] , int start , int end ,  int result[][100] , int *count){
    if(start == end){
        for(int i = 0; i <=end; i++){
            result[*count][i] = arr[i];
        }
        (*count)++;
    }
    else{
        for(int i = start; i <=end;i++){
            swap(&arr[start] , &arr[i]);
            permute(arr , start+1 , end , result , count);
            swap(&arr[start] , &arr[i]);
        }
    }
}
// void permute(int *set , int size ,  int** permutation , int idx){
//     if(idx == size){
//         permutation[factorial(size) - 1] = set;
//         return;
//     }
//     for(int i = idx; i < size; i++){
//         swap(&set[i] , &set[idx]);
//         // display(set , size);
//         permute(set , size , permutation , idx+1);
//         swap(&set[i] , &set[idx]);
//         // display(set , size);
//     }
//     return;
// }

void main(){
    int n;
    printf(" Enter the number of jobs/people : ");   
    scanf("%d" , &n);
    double cost_matrix[n][n];
    for(int i =0; i < n ; i++){
        for(int j =0; j < n ; j++){
            printf(" Enter Cost of assigning job %d to person %d " , (i+1), (j+1));
            scanf("%lf" , &cost_matrix[i][j]);
        }
    }
    printf(" Cost Matrix is : \n");
    for(int i =0; i < n ; i++){
        for(int j =0; j < n ; j++){
            printf(" %lf " , cost_matrix[i][j]);
        }
        printf("\n");
    }
    int count = 0;
    int arr[n];
    int combination[factorial(n)][100];
    for(int i = 0 ; i < n;i++){
        arr[i] = i;
    }
    permute(arr , 0 , n-1 , combination , &count);
    double sums[count];
    printf("Permutations : \n");
    for(int i = 0; i < count; i++){
        double sum = 0;
        for(int j = 0; j < n;j++){
            printf("%d" , combination[i][j]);
            sum+= cost_matrix[combination[i][j]][j];
        }
        printf("Sum is : %lf \n" , sum);
        sums[i] = sum;
        printf("\n");
    }
    for(int i = 0; i < count; i++){
        printf("Sum of Permutation %d is : %lf\n" , (i+1) , sums[i]);
    }
    double min_cost = sums[0];
    int idx  = 0;
    for(int i = 0; i< count; i++){
        if(min_cost < sums[i]){
            printf("Min Sum is : %lf \n" , min_cost);
            min_cost = sums[i];
            idx  =i;
        }
    }
    for(int i = 0 ; i < count; i++){
        printf("%d" , combination[idx][i]);
    }
    printf("\n The min Sum is : %lf\n Opcount is %d " , min_cost , count);
}