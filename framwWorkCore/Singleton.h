#pragma once

template <typename T>
class CSingleton
{
private:
	static T* m_Instance;

public:
	static T* GetInstance();
	CSingleton() { };
	virtual ~CSingleton() {};
	
};

