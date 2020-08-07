#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

int main(void)
{
        int i, j, number, temp;
        long seed;
        int arr[20];
                
        seed = time(NULL);
        srand(seed);

        printf("0이상 %d이하의 난수 20개를 생성하여 배열에 저장, 출력합니다.", MAX);

                for (i=0; i<20 ; i++){
                        number = rand()%MAX;
                        arr[i]=number;
                        printf(" %d", arr[i]);
        }
        printf("그리고");

                printf("생성된 배열을 오름차순 정렬시킵니다.");
                for(i=0; i<20 ; i++)
                {
                        for(j=i+1; j<20; j++)
                        {
                                if(arr[i]>arr[j])
                                {
                                        temp=arr[i];
                                        arr[i]=arr[j];
                                        arr[j]=temp;
                                }
                        }
                }
                for(i=0; i<20; i++)
                {
                        printf(" %d", arr[i]);
                }
                return 0;
}
