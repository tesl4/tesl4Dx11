#pragma once
class CTesl4Obj
{
	UINT m_ref;

public:

	void AddRef();
	void Release();

	CTesl4Obj();
	virtual ~CTesl4Obj();
};

