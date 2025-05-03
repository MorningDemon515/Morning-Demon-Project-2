#include "Main.h"

bool run = true;
extern HWND WindowHanled;
extern const char* WindowClass;

void InitWindow(const char* title, HINSTANCE instanceHanled, int show);

void Init_Graphics();
void Render_Graphics();
void Clean_Graphics();

int WINAPI WinMain(HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    PSTR pCmdLine,
                    int nShowCmd)
{
    InitWindow(WINDOW_TITLE,hInstance,nShowCmd);

    Init_Graphics();

    MSG msg;

    while(run)
    {
        if(PeekMessage(&msg,0,0,0,PM_REMOVE))
        {
            if(msg.message == WM_QUIT)
                run = false;

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            Render_Graphics();
        }

    }

    Clean_Graphics();
    DestroyWindow(WindowHanled);
    UnregisterClass(WindowClass, hInstance);
    return msg.wParam;
}

void ErrorMessage_1(const char* message)
{
    MessageBoxA(NULL,message,"Engine Error!",MB_OK);
}

void ErrorMessage_2(HWND hwnd,const char* message)
{
    MessageBoxA(hwnd,message,"Engine Error!",MB_OK);
}