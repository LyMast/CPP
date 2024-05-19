
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main()
{

    auto StartTime = ::chrono::high_resolution_clock::now();

    ::this_thread::sleep_for(chrono::milliseconds(3000));

    auto EndTime = ::chrono::high_resolution_clock::now();


    //chrono::duration<long long, milli> interval = EndTime - StartTime;
    auto interval = EndTime - StartTime;

    cout <<  chrono::duration_cast<chrono::duration<uint64_t, milli>>(interval).count() << "ms" <<endl;

    printf("%lld\n\n", chrono::duration_cast<chrono::duration<uint64_t, milli>>(interval).count());


    auto CheckCompile = chrono::milliseconds(10000) - chrono::duration_cast<chrono::duration<uint64_t, milli>>(interval);


    StartTime = ::chrono::high_resolution_clock::now();
    ::this_thread::sleep_for(CheckCompile);
    EndTime = ::chrono::high_resolution_clock::now();

    interval = EndTime - StartTime;

    printf("%lld\n\n", chrono::duration_cast<chrono::duration<uint64_t, milli>>(interval).count());

}