#include <list>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct _Param
{
  int callCnt;
  int threadCnt;
  int memSize;
  int usleepTime;
} Param;


void* threadProc(void* p)
{
  Param* param = (Param*)p;

  int callCnt = param->callCnt;
  int memSize = param->memSize;
  int usleepTime = param->usleepTime;




  
  for (int i = 0; i < callCnt; i++)
  {  
      struct timeval begTick, endTick; 
      gettimeofday(&begTick, NULL);
      void * mem = malloc( memSize );
      free (mem);
      gettimeofday(&endTick, NULL);
      usleep(usleepTime);
      printf("%ld\n", (endTick.tv_sec - begTick.tv_sec) * 1000000 + (endTick.tv_usec - begTick.tv_usec));
  }
  

  return NULL;
}

void usage()
{
  printf("test <call count>  <thread count> <memsize> <usleeptime>\n");
  printf("example : test 100 2 1024 1\n");
}

int main(int argc, char* argv[])
{
  if (argc != 5)
  {
    usage();
    return 0;
  }

  Param param;

  param.callCnt   = atoi(argv[1]);
  param.threadCnt = atoi(argv[2]);
  param.memSize = atoi(argv[3]);
  param.usleepTime = atoi ( argv[4]);


  std::list<pthread_t> threadList;

  for (int i = 0; i < param.threadCnt; i++)
  {
    pthread_t threadHandle;
    pthread_create(&threadHandle, NULL, threadProc, (void *)&param);
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
