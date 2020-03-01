#include <stdio.h>

void fibonacci(int n){
    int f1 = 0;
    int f2 = 1;
    if(n<=0){
        return;
    }
    else if(n==1){
        printf(" %d ", f1);
    }
    
    else if(n>1){
        printf(" %d ", f1);
        printf(" %d ", f2);

        for(int i=2; i<n; i++){
            int f3 = f1 + f2;
            printf(" %d ", f3);
            f1 = f2;
            f2 = f3;
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    fibonacci(n);
    printf("\n");
}