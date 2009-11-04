#ifndef _COMMON_H
#define _COMMON_H

#include <d3d9.h>
#include <d3dx9.h>
#include "../Vitamin/VEngine.h"

// Global Pointer
extern LPDIRECT3DDEVICE9        g_pD3DDevice;
extern class SceneEffect*       g_pSceneEffect;
extern class CGameApp*          g_pGameApp;
extern class CGraphics*         g_pGraphics;
//extern class CMessageManager*   g_pMessageManager;
//extern class GUIManager*        g_pGUIManager;

extern struct stInputInfo g_stInputInfo;

// Mouse Offset
extern long g_CursorOffsetX;
extern long g_CursorOffsetY;
extern long g_CursorOffsetZ;

#endif // _COMMON_H