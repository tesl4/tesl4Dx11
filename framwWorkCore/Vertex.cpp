#include "stdafx.h"
#include "Vertex.h"

CVertex::CVertex():m_Position(0.0f, 0.0f, 0.0f)
{

}

CVertex::CVertex(XMFLOAT3 _position) : m_Position(_position)
{
}

CVertex::CVertex(float _x, float _y, float _z) : m_Position(XMFLOAT3(_x, _y, _z))
{

}



CVertex::~CVertex()
{
}
