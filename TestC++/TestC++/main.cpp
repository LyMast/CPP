
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Interface 
{
public:

	//virtual ~Interface(void) { cout << "End Interface ~ \n"; }
	virtual ~Interface(void) = 0;

	virtual void Proc(void) = 0;

};

// 순수 가상 소멸자의 같은 경우는 이렇게 외부에 정의를 해주어야 한다.
Interface::~Interface(void) { cout << "Declare Interface ~ ! \n"; }

class CTest : public Interface
{
public:
	~CTest(void) { cout << "End Ctest ~ \n"; }

	void Proc(void)
	{
		cout << "Good!\n";
	}
};




///////////////////
//	3단
///////////////////
class Base
{
public:
	Base() { cout << typeid(this).name() << endl; }

	virtual ~Base() {}; // { cout << "~Base\n"; }
public:
	virtual void Print() = 0;

};

class Base1: public Base
{
public:
	~Base1() { cout << "~Base1\n"; }

private:
	void Print() final { cout << "\n\n1~~~~~~~~~~~~~!\n\n\n"; }

};


class Base2 : public Base1
{
public:
	Base2(void)
	{
		cout << "Arg = 0\n";
	}
	Base2(int a)
	{
		cout << " Arg = 1\n";
	}
	Base2(int a, int b)
	{
		cout << " Arg = 2\n";
	}
	Base2(int a, int b, int c)
	{
		cout << " Arg = 3\n";
	}
	Base2(int a, int b, int c, int d)
	{
		cout << " Arg = 4\n";
	}



	~Base2() { cout << "~Base2\n"; }
private:
	//void Print() { cout << "\n\n2~~~~~~~~~~~~~!\n\n\n"; }

};


template <class... _Args>
void TestArgsFunction(_Args&&... _Ax)
{
	auto Type = _STD forward<_Args>(_Ax)...;
	Base2 TestBase2(_STD forward<_Args>(_Ax)...);
}





int main()
{
	unordered_map<wstring, int> Map;
	auto pair = make_pair(L"Test", 1000);

	Map.emplace(pair);
	auto iter = Map.find(L"Test");
	if (iter == Map.end())
		printf("Noooooooooooooooooooooooooooooooooooooo~ ~ \n\n");
	else
		printf("Yesssssssssssss~ ~ \n\n");


	Map.reserve(10);
	cout << Map.size() << endl;
	for (int i = 0; i < 20; i++)
		Map.emplace(to_wstring(i), 200);

	cout << Map.size() << endl;





	CTest AA;

	Interface& cInterface = AA;

	cInterface.Proc();


	Interface* pInterface = new CTest;
	delete pInterface;




	Base* pBase = new Base2;
	pBase->Print();
	delete pBase;


	cout << "------------------------------------------------------------\n\n";

	TestArgsFunction();
	TestArgsFunction(1);
	TestArgsFunction(1,2);
	TestArgsFunction(1,2,3);
	TestArgsFunction(1,2,3,4);

	 
	cout << "------------------------------------------------------------\n\n";



	//future a;


}