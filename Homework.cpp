#include <list>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <functional>
#include <vector>
#include <numeric>
#include <algorithm>

typedef struct _Parmt // 매개인자
{
  int callCnt; // 반복회수를 받음
  int threadCnt; // 쓰레드 개수를 받음
  int memySize; // 메모리 사이즈를 받음
  int uslpTime; // main 함수의 수행동작 사이의 시간 간격(인터벌)을 받음
} Parmt;

void print_result( std::vector<int> & my_list ) {

  printf("the size of result : %lu \n" , my_list.size()  );


  sort(my_list.begin(), my_list.end());

  double avg = std::accumulate(my_list.begin(), my_list.end(), 0.0) / my_list.size();

  int result_length = my_list.size();
  int s99idx = result_length * 0.99;

  printf ("MIN : [ %d ] MAX : [ %d ] AVG[%.2lf] 99%% [%d] \n", my_list.front(), my_list.back(), avg, my_list[s99idx] );

}



void* threadProc(void* p)
{

  Parmt* para = (Parmt*)p;

  std::vector<int> result_list; 

  int callCnt = para->callCnt; 
  int memySize = para->memySize; 
  int uslpTime = para->uslpTime; 
  
  for (int i = 0; i < callCnt; i++)
  {
  struct timeval begTick; gettimeofday(&begTick, NULL);
  void * m = malloc(memySize);
  free(m);
  struct timeval endTick; gettimeofday(&endTick, NULL);
  usleep(uslpTime);

  //printf("%ld\n", (endTick.tv_sec - begTick.tv_sec) * 1000 + (endTick.tv_usec - begTick.tv_usec / 1000));

  result_list.push_back ( (endTick.tv_sec - begTick.tv_sec) * 1000 + (endTick.tv_usec - begTick.tv_usec / 1000));
  }


  print_result ( result_list );

  return NULL;
}


void usage()
{
  printf("test <call count><thread count> <memory size><usleep time>\n");
  printf("example : test 10 2 1024 3\n");
}

int main(int argc, char* argv[])
{
  if (argc != 5)
  {
    usage();
    return 0;
  }

  Parmt para;

  para.callCnt   = atoi(argv[1]);
  para.threadCnt = atoi(argv[2]);
  para.memySize = atoi(argv[3]);
  para.uslpTime = atoi(argv[4]);
  printf("callCnt=%d\n", para.callCnt);
  printf("threadCnt=%d\n", para.threadCnt);
  printf("memySize=%d\n", para.memySize);
  printf("uslpTime=%d\n", para. uslpTime);

  std::list<pthread_t> threadList;

  for (int i = 0; i < para.threadCnt; i++)
  {
    pthread_t threadHandle;
    pthread_create(&threadHandle, NULL, threadProc, (void *)&para);
    threadList.push_back(threadHandle);
  }

  for (std::list<pthread_t>::iterator it = threadList.begin(); it != threadList.end(); it++)
  {
    pthread_t threadHandle = *it;
    pthread_join(threadHandle, NULL);
  }

  threadList.clear();
  return 0;
}
