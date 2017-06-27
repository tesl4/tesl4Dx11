#include "stdafx.h"
#include "Tesl4Obj.h"


void CTesl4Obj::AddRef()
{
	m_ref++;
}

void CTesl4Obj::Release()
{
	m_ref--;
	if (m_ref < 1) delete this;
}

CTesl4Obj::CTesl4Obj()
{
	m_ref=1;
}


CTesl4Obj::~CTesl4Obj()
{
}
