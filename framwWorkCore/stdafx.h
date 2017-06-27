// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <iostream>
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <vector>

//Directx Includes
#include <d3d11.h>
#include <d3dx11.h>
#include <D3DX10Math.h>
#include <d3dcompiler.h>
#include <xnamath.h>

//tesl4's 
#include "Singleton.h"
#include "Render.h"

#include "Vertex.h"
#include "Tesl4Obj.h"
#include "ShaderBase.h"
#include "ShaderInAct.h"
#include "Mesh.h"


/*
#include "Mesh.h"
#include "Shader.h"
#include "Object.h"
*/

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
