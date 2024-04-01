#include <stdio.h>

int fibonacciGenerator(int numberOfTerms){
    if(numberOfTerms == 1){
        return 1;
    }
    else if(numberOfTerms <= 0){
        return 0;
    }
    else{
        return fibonacciGenerator(numberOfTerms - 1) + fibonacciGenerator(numberOfTerms - 2); 
    }
}

void main(){
    int n;
    printf("Enter Number of required terms : ");
    scanf("%d" , &n);
    int x = 1;
    while(x <= n){
        printf("Fibonacci(%d) = %d\n" ,x ,  fibonacciGenerator(x));
        x++;
    }
}