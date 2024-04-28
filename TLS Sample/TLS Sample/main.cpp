
#include <iostream>
#include <Windows.h>
#include <thread>

thread_local int iValue;
using namespace std;

int main(void)
{
	printf("thread id = %d!! LOCAL_VALUE = %d\n\n", GetCurrentThreadId(), iValue);
	iValue = 10;
	printf("thread id = %d!! LOCAL_VALUE = %d\n\n", GetCurrentThreadId(), iValue);


	auto pthread = new thread([]()->void{
		printf("thread id = %d!! LOCAL_VALUE = %d\n\n", GetCurrentThreadId(), iValue);
		iValue = 200;
		printf("thread id = %d!! LOCAL_VALUE = %d\n\n", GetCurrentThreadId(), iValue);
	});


	// 윈도우 GetCurrentThreadId와는 다르게 동작한다. this를 통해서 데이터를 가져오지만, 
	// 실제 GetCurrentThreadId와 값이 같으것으로 보아 thread에 최상단에 해당 데이터를 미리 집어 놓은 듯함
	cout << pthread->get_id() <<endl << endl;


	pthread->join();
	delete pthread;


	printf("thread id = %d!! LOCAL_VALUE = %d\n\n", GetCurrentThreadId(), iValue);
	



}