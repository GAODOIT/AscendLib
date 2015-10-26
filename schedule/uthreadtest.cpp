// kcoroutine.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "uthread.h"
class runable_test : public runnable
{
public:
    runable_test(const char *name):name(name){}
    void main_routine()
    {
        for(int i =0 ; i < 10 ; ++i)
        {
            printf("%s/n",name);
            u_thread::sleep(uid,1);
            printf("%s wake up/n",name);
        }
    }
    const char *name;
    uthread_id uid;
};
int main()
{
    //���ȳ�ʼ��������
    Scheduler::scheduler_init();
    
    
    runable_test t1("0");
    runable_test t2("1");
    runable_test t3("2");
    runable_test t4("3");
    
    //����4���û����߳�
    t1.uid = Scheduler::uthread_create(&t1,4096);
    t2.uid = Scheduler::uthread_create(&t2,4096);
    t3.uid = Scheduler::uthread_create(&t3,4096);
    t4.uid = Scheduler::uthread_create(&t4,4096);
    
    printf("create finish/n");
    //��ʼ�����̵߳�����
    Scheduler::schedule();
    return 0;
}