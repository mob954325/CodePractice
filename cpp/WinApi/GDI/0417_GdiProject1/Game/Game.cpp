#include "framework.h"
#include "Game.h"
#include "GameApp.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    GameApp app;

    app.Initialize();

    app.Run();
    app.Shutdown();
    return (int)1;
}