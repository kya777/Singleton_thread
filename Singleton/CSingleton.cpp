#include "CSingleton.h"
#include <iostream>
#include <mutex>

CSingleton& CSingleton::GetObj()
{
	static CSingleton Obj;
	return Obj;
}

void CSingleton::AddTestNum()
{
	std::mutex mu;
	mu.lock();
	Test_Nun = Test_Nun + 1;
	mu.unlock();
}

CSingleton::CSingleton()
{

	std::cout << "Call Construction" << std::endl;
	
}

CSingleton::~CSingleton()
{

	std::cout << "Call Destruction" << std::endl;

}
