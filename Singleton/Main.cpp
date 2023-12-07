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
	int d = 0;

	thread thread1(&a, std::ref(mu));
	thread thread2(&a, std::ref(mu));

	


	thread1.join();
	thread2.join();


	std::cout << temp.GetObj().GetTestNum() << std::endl;


	return 0;
}