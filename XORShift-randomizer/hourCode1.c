#include <stdio.h>
#include <stdint.h>
#include <time.h>

int random_state = 1234;

static inline int random_int(){
    int n = random_state;
    n ^= n << 13;
    n ^= n >> 17;
    n ^= n << 5;
    random_state = n;
    return n;
}

int main(){
    random_state = time(NULL);
    random_state = random_int();
    printf("Enter the number of wished random numbers: \n");
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x = random_int();
        printf(" %u \n", x);
    }
}