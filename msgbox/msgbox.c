#include <windows.h>

INT WINAPI
WinMain(HINSTANCE   hInstance,
        HINSTANCE   hPrevInstance,
        LPSTR       lpCmdLine,
        INT         nCmdShow)
{
    if (MessageBoxA(NULL,
                    "Are you a student in this school?",
                    "msgbox.c",
                    MB_YESNO | MB_ICONINFORMATION) == IDYES)
    {
        MessageBox(NULL, TEXT("You are a student in this school."), TEXT("msgbox.c"), MB_ICONINFORMATION);
    }
    else
    {
        MessageBoxW(NULL, L"You are not a student in this school.", L"msgbox.c", MB_ICONERROR);
    }
    return 0;
}
