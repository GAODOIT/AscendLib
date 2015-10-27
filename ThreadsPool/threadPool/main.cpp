//http://www.cnblogs.com/osyun/archive/2012/08/31/2664938.html
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "thread_pool.h"
#include "command.h"

int main()
{
    ThreadPool thread_pool;
    thread_pool.InitializeThreads();
    Command command;
    char arg[8] = {0};
    for(int i=1; i<=1000; ++i)
    {
        command.set_cmd(i%3);
        sprintf(arg,"%d",i);
        command.set_arg(arg);
        thread_pool.AddWork(command);
    }
    sleep(10); // 用于测试线程池缩容
    thread_pool.ThreadDestroy();
    return 0;
}
