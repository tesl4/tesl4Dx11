#pragma once

#include "ShaderBase.h"
class CActor;

class CShaderInAct : public CShaderBase
{
	std::vector<CActor*> m_actors;

public:
	CShaderInAct();
	virtual ~CShaderInAct();
};

