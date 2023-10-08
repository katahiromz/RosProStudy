#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include "resource.h"

LPCTSTR doLoadString(INT nID)
{
    static TCHAR s_szText[MAX_PATH];
    s_szText[0] = 0;
    LoadString(NULL, nID, s_szText, _countof(s_szText));
    return s_szText;
}

// EN_CHANGE
BOOL OnChange(HWND hwnd)
{
    BOOL bOK;
    INT nValue1 = GetDlgItemInt(hwnd, edt1, &bOK, TRUE);
    if (!bOK)
    {
        SetDlgItemText(hwnd, edt3, doLoadString(IDS_ERROR));
        return FALSE;
    }
    INT nValue2 = GetDlgItemInt(hwnd, edt2, &bOK, TRUE);
    if (!bOK)
    {
        SetDlgItemText(hwnd, edt3, doLoadString(IDS_ERROR));
        return FALSE;
    }
    INT nValue3 = nValue1 * nValue2;
    SetDlgItemInt(hwnd, edt3, nValue3, TRUE);
    return TRUE;
}

BOOL OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
    SetDlgItemInt(hwnd, edt1, 1, TRUE);
    SetDlgItemInt(hwnd, edt2, 2, TRUE);
    return TRUE;
}

void OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch (id)
    {
    case IDOK:
    case IDCANCEL:
        EndDialog(hwnd, id);
        break;
    case edt1:
    case edt2:
        if (codeNotify == EN_CHANGE)
        {
            OnChange(hwnd);
        }
        break;
    }
}

INT_PTR CALLBACK
DialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        HANDLE_MSG(hwnd, WM_INITDIALOG, OnInitDialog);
        HANDLE_MSG(hwnd, WM_COMMAND, OnCommand);
    }
    return 0;
}

INT WINAPI
WinMain(HINSTANCE   hInstance,
        HINSTANCE   hPrevInstance,
        LPSTR       lpCmdLine,
        INT         nCmdShow)
{
    InitCommonControls();
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_MAIN), NULL, DialogProc);
    return 0;
}
