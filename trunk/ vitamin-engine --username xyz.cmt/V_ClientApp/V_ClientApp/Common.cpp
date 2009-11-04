#include "../Vitamin/VEngine.h"

stInputInfo         g_stInputInfo;          //ノ办: GameApp(MainLoop)
LPDIRECT3DDEVICE9   g_pD3DDevice = NULL;    //ノ办: GameApp(Init~Destory)
SceneEffect*        g_pSceneEffect = NULL;
CGameApp*           g_pGameApp = NULL;      //ノ办: GameApp(CONSTRUCTOR~DESTRUCTOR)
CGraphics*          g_pGraphics = NULL;     //ノ办: GameApp(Init~Destory)
CInput              g_Input;                //ノ办: GameApp( Init(CreateInput)~Destory(ReleaseInput) )
//GFont               g_Font;                 //ノ办: GameApp(Init~ )
//GUIManager*         g_pGUIManager = NULL;   //ノ办: GameApp(Init~Destory)
//CMessageManager*    g_pMessageManager = NULL;

// Mouse Offset
long g_CursorOffsetX = 0;
long g_CursorOffsetY = 0;
long g_CursorOffsetZ = 0;