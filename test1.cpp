#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define SIZE 10
 
void insert_rand(int* n);
void print_arr(int* n);
void print_max(int* n);
void print_min(int* n);
 
int main() {
    int arr[SIZE] = {0};
 
    insert_rand(arr);
    print_arr(arr);
    print_max(arr);
    print_min(arr);
 
    return 0;
}
 
void insert_rand(int* n) {
    int i;
    int n;
    srand((unsigned)time(NULL));
 
    for(i=0; i<SIZE; i++)
    for(n=0; n<100; n++)
        n[i] = rand();
}
void print_arr(int* n) {
    int i;
    
    for(i=0; i<SIZE; i++) {
        printf("%d ", n[i]);
    }
    printf("\n");
}
void print_max(int* n) {
    int i, max;
    
    max = n[0];
    for(i=0; i<SIZE; i++) {
        if(max <= n[i])
            max = n[i];
    }
    printf("최댓값: %d \n", max);
}
void print_min(int* n) {
    int i, min;
    
    min = n[0];
    for(i=0; i<SIZE; i++) {
        if(min >= n[i])
            min = n[i];
    }
    printf("최솟값: %d \n", min);
}