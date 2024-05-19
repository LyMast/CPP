#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>

using namespace std;

#define df_THREAD_COUNT 10
#define df_LOOP_COUNT 10000
#define df_TEST2

class TestClass 
{
public:
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
};

static mutex g_MutexLock;
static shared_mutex g_SharedMutexLock;
static TestClass g_TestClass;

void ThreadFunc();

int main(int argc, char* argv[])
{

    thread* pThread[df_THREAD_COUNT];

    for(int i = 0; i < df_THREAD_COUNT; ++i)
    {
        pThread[i] = new thread(ThreadFunc);
    }



    for(int i = 0; i < df_THREAD_COUNT; ++i)
    {
        pThread[i]->join();
        delete pThread[i];
    }

    printf("-a:%d\n-b:%d\n-c:%d\n-d:%d\n-e:%d\n\n",
            g_TestClass.a, g_TestClass.b, g_TestClass.c, g_TestClass.d, g_TestClass.e);


    return 0;
}



#ifdef  df_TEST1
// 기본 뮤텍스를 확인하기 위한 코드
void ThreadFunc()
{

    adopt_lock_t ad;
    for(int i = 0 ; i < df_LOOP_COUNT ; ++i)
    {
        /*  일반적인 lOCK, UNLOCK  뮤텍스
        g_MutexLock.lock();

        g_TestClass.a++;
        g_TestClass.b++;
        g_TestClass.c++;
        g_TestClass.d++;
        g_TestClass.e++;

        g_MutexLock.unlock();
        //*/  


        {
            // Case 1 : 정상적으로 Lock Unlcok이 잘 일어난다.
            //lock_guard lock(g_MutexLock);

            // Case 2 : adopt_lock은 현재 스레드에서 재귀적인 Lock을 방지하는데 사용하는데, 여기서 아무 작없이 이런 행위를 하면은 동기화가 잡히지 않는 문제가 생긴다.
            //lock_guard lock(g_MutexLock, adopt_lock);


            // Case 3 : Unique_lock에 대한 실험 코드. 잘 진행이 된다.
            /*
                Unique Lock에 대한 추가적인 설명 : 전문가 p.1154
                    - 락을 선언하고 한참 뒤 실행할 때 락을 걸도록 지연시키는 고급 기능을 제공한다. 락이 제대로 걸렸는지 확인하려면, owns_lock 메서드나 unique_lock에서 제공하는 bool 타입 연산자를 사용한다.
                      위의 변환 연산자를 사용하는 방법은 1160에 시간 재약이 있는 락 사용하기에서 자세히 소개
            */
            unique_lock lock(g_MutexLock);

            g_TestClass.a++;
            g_TestClass.b++;
            g_TestClass.c++;
            g_TestClass.d++;
            g_TestClass.e++;    

        }

    }
    
}
#endif



#ifdef  df_TEST2
//  adopt_lock을 테스트 하가위한 코드
void ThreadFunc()
{

    adopt_lock_t ad;
    for(int i = 0 ; i < df_LOOP_COUNT ; ++i)
    {
        g_MutexLock.lock();

        {
            // 이미 걸려있는 뮤텍스의 상태를 인수하고, lock 객체의 생명주기가 끝날 때, g_MutexLock객체를 unlock한다. 
            // 이때, adopt_lock은 따로 선언 없이 사용할 수 있다. 해당 태그는 이미 lock이 걸려 있는 mutext객체를 lock_guard나 unique_lock 객체에 전달할 때 사용한다.
            // 해당 lock 관리 객체는 새로운 lock을 시도하지 않고, 기존의 lock 상태를 "인수"합니다. 따라서, std::adopt_lock은 단순히 생성자에 전달하는 인자로 사용되며, 별도로 선언할 필요는 없습니다.
            lock_guard lock(g_MutexLock, adopt_lock);


            // 위의 락을 주석 처리하고 다음 Scope에서 adopt_lock을 하면은 데드락이 발생한다.
            //lock_guard lock(g_MutexLock);
            

            //*
            {
                // Case1 : 위의 코드를 그대로 넣고 돌리면 비정상 종료
                // Case2 : 위의 코드를 제거하고 돌리면 동기화가 잡히지 않음. 뮤텍스의 해제시점이 객체 소멸시점과 일치하는 것을 확인 가능
                // Case3 : adopt_lock에 다른 adopt_lock을 넣어주거나 선언해도 컴파일이 안된다

                //adopt_lock_t adopt_lock2;
                //lock_guard lock2(g_MutexLock, adopt_lock);
            }
            //*/

            g_TestClass.a++;
            g_TestClass.b++;
            g_TestClass.c++;
            g_TestClass.d++;
            g_TestClass.e++;    

            // 정상 작동

        }

    }
    
}

#endif