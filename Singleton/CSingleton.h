#pragma once
class CSingleton
{
public:
	static CSingleton& GetObj();
	void AddTestNum();
	int GetTestNum() { return Test_Nun; }
private:
	CSingleton();
	~CSingleton();

private:
	unsigned int Test_Nun = 0;
};

