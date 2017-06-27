#pragma once

#include "ShaderBase.h"
class CActor;

class CShaderInAct : public CShaderBase
{
	std::vector<CActor*> m_actors;


public:

	virtual bool CreateShader() override;

	CShaderInAct();
	CShaderInAct(WCHAR* _fileName);
	virtual ~CShaderInAct();
};

