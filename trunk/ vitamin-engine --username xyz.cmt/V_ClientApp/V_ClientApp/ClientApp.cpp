#include "ClientApp.h"
#include "Common.h"


CClinetApp::CClinetApp()
{

}

CClinetApp::~CClinetApp()
{

}

BOOL CClinetApp::InitGameApp(HINSTANCE hInstance, int nCmdShow, const char* szCaption /*= "Vitamin Engine"*/, const char* szIcon /*= IDI_APPLICATION*/)
{
    SetDLLFileLog(true);
    CGameApp::InitGameApp(hInstance, nCmdShow, szCaption, szIcon);

    g_pD3DDevice = GetD3DDevice();
    g_pSceneEffect = GetSceneEffect();
    g_pGameApp   = GetMainApp();
    g_pGraphics  = GetGraphics();
    g_stInputInfo = GetInputInfo();

    SetFPS(0);

    OnLostDevice();

    return TRUE;
}

BOOL CClinetApp::Destroy(void)
{
    CGameApp::Destroy();
    
    //---------------------
    g_pD3DDevice = GetD3DDevice();
    g_pGameApp   = GetMainApp();
    g_pGraphics  = GetGraphics();
    //---------------------

    return TRUE;
}

void CClinetApp::MainLoop(void)
{
    g_stInputInfo = GetInputInfo();
    ::GetPointerOffset(&g_CursorOffsetX, &g_CursorOffsetY, &g_CursorOffsetZ);

    // Render Begin
    g_pGraphics->BeginScene();
    
    g_pGraphics->Render3DObject();

    g_pGraphics->EndScene();
 
}

void CClinetApp::OnLostDevice(void)
{
    D3DLIGHT9 light;
    ::RtlZeroMemory(&light, sizeof(light));

    light.Type      = D3DLIGHT_DIRECTIONAL;
    light.Ambient.r  = 0.7f;
    light.Ambient.g  = 0.7f;
    light.Ambient.b  = 0.7f;
    light.Ambient.a  = 0.7f;
    light.Diffuse.r  = 0.8f;
    light.Diffuse.g  = 0.8f;
    light.Diffuse.b  = 0.8f;
    light.Diffuse.a  = 0.5f;
    light.Specular.r = 1.0f * 0.6f;
    light.Specular.g = 1.0f * 0.6f;
    light.Specular.b = 1.0f * 0.6f;
    light.Specular.a = 1.0f * 0.6f;
    light.Direction.x = -0.2f;
	light.Direction.y = -0.39f;
	light.Direction.z = -0.9f;

	//	light.Position = D3DXVECTOR3(1290, 136, 3921);
	//	light.Range       = 1000.0f;

	g_pD3DDevice->SetLight(0, &light);
	g_pD3DDevice->LightEnable(0, FALSE);

	g_pD3DDevice->SetRenderState(D3DRS_NORMALIZENORMALS, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SPECULARENABLE, FALSE);
	g_pD3DDevice->SetRenderState(D3DRS_AMBIENT, 0xff7f7f7f);

	SetFog(1200);
	
	if(IsSupportFSAA())
	{
		g_pD3DDevice->SetRenderState(D3DRS_MULTISAMPLEANTIALIAS, TRUE);
	}
	else
	{
		g_pD3DDevice->SetRenderState(D3DRS_MULTISAMPLEANTIALIAS, FALSE);
	}

	g_pD3DDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	g_pD3DDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	g_pD3DDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);
	g_pD3DDevice->SetSamplerState(1, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	g_pD3DDevice->SetSamplerState(1, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	g_pD3DDevice->SetSamplerState(1, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);
}

void CClinetApp::SetFog(int end)
{
	//_FOG_________________________________________________________________
	float Start = 200.0f, End = (float)end;
	g_pD3DDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);
	g_pD3DDevice->SetRenderState(D3DRS_FOGCOLOR, 0x00a4a4a4);
	g_pD3DDevice->SetRenderState(D3DRS_FOGVERTEXMODE, D3DFOG_LINEAR);
	g_pD3DDevice->SetRenderState(D3DRS_FOGSTART, *(DWORD*)(&Start));
	g_pD3DDevice->SetRenderState(D3DRS_FOGEND, *(DWORD*)(&End));
	//_FOG_________________________________________________________________
}