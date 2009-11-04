#ifndef _CLIENT_APP_H
#define _CLIENT_APP_H

#include "../Vitamin/VEngine.h"

class CClinetApp : public CGameApp
{
public:
    CONSTRUCTOR CClinetApp();
    DESTRUCTOR ~CClinetApp();

    virtual BOOL InitGameApp(HINSTANCE hInstance, int nCmdShow, const char* szCaption = "Vitamin Engine", const char* szIcon = IDI_APPLICATION);
    virtual BOOL Destroy(void);
    virtual void MainLoop(void);

    void OnLostDevice(void);

    void SetFog(int end);

};

#endif