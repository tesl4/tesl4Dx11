#pragma once
#include "Tesl4Obj.h"

class CMesh;

class CActor : public CTesl4Obj
{

	CMesh* m_pMesh;

public:
	CActor();
	virtual ~CActor();
};

