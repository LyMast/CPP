
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


	// ������ GetCurrentThreadId�ʹ� �ٸ��� �����Ѵ�. this�� ���ؼ� �����͸� ����������, 
	// ���� GetCurrentThreadId�� ���� ���������� ���� thread�� �ֻ�ܿ� �ش� �����͸� �̸� ���� ���� ����
	cout << pthread->get_id() <<endl << endl;


	pthread->join();
	delete pthread;


	printf("thread id = %d!! LOCAL_VALUE = %d\n\n", GetCurrentThreadId(), iValue);
	



}