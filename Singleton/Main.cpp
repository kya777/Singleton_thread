#include <iostream>
#include <thread>
#include <mutex>
#include "CSingleton.h"
using namespace std;

void a(mutex& mu)
{
	CSingleton& temp = CSingleton::GetObj();
	
	lock_guard<mutex> lg(mu);

	for (unsigned int i = 0; i < 1000000; i++)
	{
		temp.GetObj().AddTestNum();
	}
}


int main()
{
	CSingleton& temp = CSingleton::GetObj();

	mutex mu;

	// 하나의 mutex로 관리해야 함
	// thread가 2개라고 2개의 mutex로 잠구면 잠겨있는지 몰라서 레이스컨디션이 발생함.
	// 데드락을 피하기 위해 std::lock_gard를 사용함.
	thread thread1(&a, std::ref(mu));
	thread thread2(&a, std::ref(mu));

	thread1.join();
	thread2.join();

	std::cout << temp.GetObj().GetTestNum() << std::endl;

	return 0;
}