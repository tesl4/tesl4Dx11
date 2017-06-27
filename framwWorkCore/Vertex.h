#pragma once
#include "Tesl4Obj.h"
class CVertex : public CTesl4Obj
{
	XMFLOAT3 m_Position;

public:
	CVertex();
	CVertex(XMFLOAT3 _posiion);
	CVertex(float _x, float _y, float _z);
	virtual ~CVertex();
};

