#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
     
    int i;
    srand(time(NULL));
    for (i = 1; i <= 10; i++) 
        printf("%d ", (rand() % 1000000) + 1);
    printf("\n");
}
