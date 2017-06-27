#pragma once
class CFWObject
{
	int m_RefCount;
public:

	void AddRef();
	void RelaseRef();

	CFWObject();
	~CFWObject();
};

