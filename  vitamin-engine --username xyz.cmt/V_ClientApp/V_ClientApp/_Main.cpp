#include "ClientApp.h"
#include "resource.h"

//+----------------------------------
//| WinMain
//+----------------------------------
int PASCAL WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
    CClinetApp app;
    app.InitGameApp(hInst, nCmdShow, "VE ClientApp", MAKEINTRESOURCE(IDI_MAINICON));
    app.Run();
    app.Destroy();

    return 1;
}