#include "../Vitamin/VEngine.h"

stInputInfo         g_stInputInfo;          //�@�ΰ�: GameApp(MainLoop)
LPDIRECT3DDEVICE9   g_pD3DDevice = NULL;    //�@�ΰ�: GameApp(Init~Destory)
SceneEffect*        g_pSceneEffect = NULL;
CGameApp*           g_pGameApp = NULL;      //�@�ΰ�: GameApp(CONSTRUCTOR~DESTRUCTOR)
CGraphics*          g_pGraphics = NULL;     //�@�ΰ�: GameApp(Init~Destory)
CInput              g_Input;                //�@�ΰ�: GameApp( Init(CreateInput)~Destory(ReleaseInput) )
//GFont               g_Font;                 //�@�ΰ�: GameApp(Init~ )
//GUIManager*         g_pGUIManager = NULL;   //�@�ΰ�: GameApp(Init~Destory)
//CMessageManager*    g_pMessageManager = NULL;

// Mouse Offset
long g_CursorOffsetX = 0;
long g_CursorOffsetY = 0;
long g_CursorOffsetZ = 0;