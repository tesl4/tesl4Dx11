#include "stdafx.h"
#include "TriangleActor.h"


TriangleActor::TriangleActor()
{
}

TriangleActor::~TriangleActor()
{
}

void TriangleActor::Tick(float delta)
{
	CActor::Tick(delta);
}

void TriangleActor::Render()
{
	std::cout << "TriangleActor->";

	CActor::Render();
}
