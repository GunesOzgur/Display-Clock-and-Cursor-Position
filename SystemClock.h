// SystemClock.h
// contains varible definitions and function declarations

#ifndef FS_SYSTEMCLOCK_H
#define FS_SYSTEMCLOCK_H
#endif

#include <windows.h>

static char Wnd_szClassName[] = "SevenSementDisplayClass";
static HINSTANCE Wnd_hInst = NULL;

static HBRUSH Wnd_bg = (HBRUSH)(COLOR_BTNFACE+1);

HBITMAP hbmSgmMask0;
HBITMAP hbmSgmMask1;
HBITMAP hbmSgmMask2;
HBITMAP hbmSgmMask3;
HBITMAP hbmSgmMask4;
HBITMAP hbmSgmMask5;
HBITMAP hbmSgmMask6;
HBITMAP hbmSgmMask7;
HBITMAP hbmSgmMask8;
HBITMAP hbmSgmMask9;

HBITMAP hbmSgmColon;

HBITMAP hbmSgmBlue;

BITMAP bm0;
BITMAP bm1;
BITMAP bm2;
BITMAP bm3;
BITMAP bm4;
BITMAP bm5;
BITMAP bm6;
BITMAP bm7;
BITMAP bm8;
BITMAP bm9;

void DrawDigit(HDC hdc, int digit, int PosX, int PosY);
void UpdateDigit(HWND Hwnd, int PosX, int PosY, int NewValue);