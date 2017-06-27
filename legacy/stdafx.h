// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"
#include "resource.h"

// Windows ��� ����:
#include<windows.h>
#include <iostream>
#include <ctime>
#include <thread>
//d3d
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>
#include <dxfile.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <list>
#include <vector>


//Tesl4->Framework Part
#include "structs.h"
#include "RenderDX11.h" 
#include "Scene.h"
#include "Mesh.h"
#include "Vertex.h"
#include "Actor.h"
#include "TimeMgr.h" 
#include "ShaderObj.h" 


//Tesl4->Content Part
#include "Triangles.h"
#include "TriangleActor.h"






//typedefs
#define null	nullptr



// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
#define PATH_KAROK_X L"res/kalok.x";