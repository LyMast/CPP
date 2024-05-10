
#include <iostream>

using namespace std;

class TEST
{
public:

    TEST(void)
    {
        cout << "생성자 호출!!!" << endl;
    }
    ~TEST(void)
    {
        cout << "소멸자 호출!!!" << endl;
    }

//*
    void* operator new (size_t N)
    {
        return aligned_alloc(64, N);
    }

	void operator delete(void* adr)
	{
		free(adr);
	}
//*/


private:

    int _x;
    int _y;


};

// 테스트 방법 : 위의 operator new, delete를 주석처리하고 말고를 비교하면 된다.
int main()
{

    TEST* p = new TEST;
    printf("%p -- aligned? : %llu  (Not 0, Not Aligned)\n", p, (uint64_t)p % 64);

    delete p;
    printf("%p\n", p);



    return 0;
}