
#include <iostream>
#include <thread>

thread_local int iValue;
using namespace std;

int main(void)
{
	printf("thread id = %lld!! LOCAL_VALUE = %d\n\n", this_thread::get_id(), iValue);
	iValue = 10;
	printf("thread id = %lld!! LOCAL_VALUE = %d\n\n",  this_thread::get_id(), iValue);


	auto pthread = new thread([]()->void{
		printf("thread id = %lld!! LOCAL_VALUE = %d\n\n",  this_thread::get_id(), iValue);
		iValue = 200;
		printf("thread id = %lld!! LOCAL_VALUE = %d\n\n",  this_thread::get_id(), iValue);
	});


	cout << pthread->get_id() <<endl << endl;


	pthread->join();
	delete pthread;


	printf("thread id = %lld!! LOCAL_VALUE = %d\n\n",  this_thread::get_id(), iValue);
	



}