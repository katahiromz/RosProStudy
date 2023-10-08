#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>

#define CLASSNAME TEXT("winapp")

HINSTANCE g_hInst = NULL;
HWND g_hMainWnd = NULL;

// WM_CREATE
BOOL OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct)
{
    g_hMainWnd = hwnd;
    return TRUE;
}

// WM_PAINT
void OnPaint(HWND hwnd)
{
    PAINTSTRUCT ps;
    if (HDC hdc = BeginPaint(hwnd, &ps))
    {
        RECT rc;
        GetClientRect(hwnd, &rc)+

        MoveToEx(hdc, 0, 0, NULL);
        LineTo(hdc, rc.right, rc.bottom);

        MoveToEx(hdc, rc.right, 0, NULL);
        LineTo(hdc, 0, rc.bottom);

        UINT uFormat = DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_NOPREFIX;
        SetTextColor(hdc, RGB(255, 0, 0));
        SetBkColor(hdc, RGB(255, 255, 0));
        DrawText(hdc, TEXT("Hello, Win32"), -1, &rc, uFormat);

        EndPaint(hwnd, &ps);
    }
}

// WM_SIZE
void OnSize(HWND hwnd, UINT state, int cx, int cy)
{
    if (!hwnd)
        return;

    RECT rc;
    GetClientRect(hwnd, &rc);

    // TODO: Do something
}

// WM_DESTROY
void OnDestroy(HWND hwnd)
{
    PostQuitMessage(0);
}

LRESULT CALLBACK
WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        HANDLE_MSG(hwnd, WM_CREATE, OnCreate);
        HANDLE_MSG(hwnd, WM_PAINT, OnPaint);
        HANDLE_MSG(hwnd, WM_SIZE, OnSize);
        HANDLE_MSG(hwnd, WM_DESTROY, OnDestroy);
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

INT WINAPI
WinMain(HINSTANCE   hInstance,
        HINSTANCE   hPrevInstance,
        LPSTR       lpCmdLine,
        INT         nCmdShow)
{
    g_hInst = hInstance;

    InitCommonControls();

    WNDCLASSEX wcx = { sizeof(wcx), CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS };
    wcx.lpfnWndProc     = WindowProc;
    wcx.hInstance       = hInstance;
    wcx.hIcon           = LoadIcon(NULL, IDI_APPLICATION);
    wcx.hCursor         = LoadCursor(NULL, IDC_ARROW);
    wcx.hbrBackground   = (HBRUSH)(COLOR_3DFACE + 1);
    wcx.lpszClassName   = CLASSNAME;
    if (!RegisterClassEx(&wcx))
    {
        MessageBoxA(NULL, "RegisterClassEx failed", NULL, MB_ICONERROR);
        return 1;
    }

    DWORD exstyle = 0;
    DWORD style = WS_OVERLAPPEDWINDOW;

    HWND hwnd = CreateWindowEx(exstyle, CLASSNAME, TEXT("winapp"), style,
        CW_USEDEFAULT, CW_USEDEFAULT, 320, 120,
        NULL, NULL, hInstance, NULL);
    if (!hwnd)
    {
        MessageBoxA(NULL, "CreateWindowEx failed", NULL, MB_ICONERROR);
        return 1;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (INT)msg.wParam;
}
