
//#define 

#include <Windows.h>
#include <iostream>
#include <chrono>

#pragma comment(lib, "Winmm.lib")

using namespace std;

int main(void)
{
	///////////////////////////////////
	//		Duration
	// 
	// - 두 시점 사이의 시간 간격을 표현하는 클래스 템플릿으로서 "틱"과 틱 주기에 대한 값을 저장한다.
	//			>> 틱 주기 : 두 틱 사이의 초 단위 간격으로서 컴파일 시간 상수인  ratio로 표현한다. 따라서 초를 분수로 표현한 것이다.
	///////////////////////////////////


	// Duration Template : template <class Rep, class Period = ratio<1>> class duration {  ...  }			2가지 매개변수를 받는다.
	//		1. class Rep : 틱 수를 저장하는 변수 타입. 반드시 double, int같은 산술 타입으로 표현한다.
	//		2. class Period : 유리수 상수로서 틱의 주기를 표현한다. 틱의 주기를 지정하지 않은면 1초에 해당하는 디폴트 값인 ratio<1>이 적용된다.


	// Test 항목 : window의 timeGetPeriod(1); 과 똑같이 동작하는가?
	//		Issue : Windows11에서는 원하는 현상이 나오지 않는다.
	// 
	int timeInterval1, start1, end1;


	start1 = timeGetTime();
	/*
	Sleep(1000);
	end1 = timeGetTime();
	printf("Before timeBeginPeriod - %d\n", end1 - start1);
	//*/

	do
	{
		end1 = timeGetTime();
		printf("Before timeBeginPeriod - %d\n", end1);
	} while (end1 - start1 < 100);

	int a;
	cout << "Enter Any Key to Start TimeGetTime Test : ";
	cin >> a;

	auto Ret = timeBeginPeriod(10);
	if (Ret != TIMERR_NOERROR)
		cout << "Error!!!!!!\n\n\n";

	

	
	start1 = timeGetTime();
	/*
	Sleep(1000);
	end1 = timeGetTime();
	printf("After timeBeginPeriod - %d\n", end1 - start1);
	//*/

	do
	{
		end1 = timeGetTime();
		printf("Before timeBeginPeriod - %d\n", end1);
	} while (end1 - start1 < 100);


	Ret = timeBeginPeriod(16);
	if (Ret != TIMERR_NOERROR)
		cout << "Error!!!!!!\n\n\n";










	// 생성자에는 3가지 버전이 있다.





	///////////////////////////////////
	//		Clock
	///////////////////////////////////




	///////////////////////////////////
	//		time_point
	///////////////////////////////////


	return 0;
}