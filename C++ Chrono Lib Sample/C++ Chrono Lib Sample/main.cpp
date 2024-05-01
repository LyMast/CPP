
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
	// - �� ���� ������ �ð� ������ ǥ���ϴ� Ŭ���� ���ø����μ� "ƽ"�� ƽ �ֱ⿡ ���� ���� �����Ѵ�.
	//			>> ƽ �ֱ� : �� ƽ ������ �� ���� �������μ� ������ �ð� �����  ratio�� ǥ���Ѵ�. ���� �ʸ� �м��� ǥ���� ���̴�.
	///////////////////////////////////


	// Duration Template : template <class Rep, class Period = ratio<1>> class duration {  ...  }			2���� �Ű������� �޴´�.
	//		1. class Rep : ƽ ���� �����ϴ� ���� Ÿ��. �ݵ�� double, int���� ��� Ÿ������ ǥ���Ѵ�.
	//		2. class Period : ������ ����μ� ƽ�� �ֱ⸦ ǥ���Ѵ�. ƽ�� �ֱ⸦ �������� ������ 1�ʿ� �ش��ϴ� ����Ʈ ���� ratio<1>�� ����ȴ�.


	// Test �׸� : window�� timeGetPeriod(1); �� �Ȱ��� �����ϴ°�?
	//		Issue : Windows11������ ���ϴ� ������ ������ �ʴ´�.
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










	// �����ڿ��� 3���� ������ �ִ�.





	///////////////////////////////////
	//		Clock
	///////////////////////////////////




	///////////////////////////////////
	//		time_point
	///////////////////////////////////


	return 0;
}