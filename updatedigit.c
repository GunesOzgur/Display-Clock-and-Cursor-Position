/*
* updatedigit.c
*
* contains UpdateDigit() function definition
*
* External Variables:
*	- Wnd_bg
*	- hbmSgmMask0;
*	- hbmSgmMask1;
*	- hbmSgmMask2;
*	- hbmSgmMask3;
*	- hbmSgmMask4;
*	- hbmSgmMask5;
*	- hbmSgmMask6;
*	- hbmSgmMask7;
*	- hbmSgmMask8;
*	- hbmSgmMask9;
*	- hbmSgmBlue;
*	- bm0;
*/

#include "SystemClock.h"

void UpdateDigit(HWND Hwnd, int PosX, int PosY, int NewValue)
{

	HDC hdc;
	hdc = GetDC(Hwnd);

	RECT rc;
	rc.left = PosX;
	rc.top = PosY;
	rc.right = PosX + bm0.bmWidth;
	rc.bottom = PosY + bm0.bmHeight;
	FillRect(hdc, &rc, Wnd_bg);

	HDC hdcMemory;
	hdcMemory = CreateCompatibleDC(hdc);

	switch(NewValue) {

		case 0:
			SelectObject(hdcMemory, hbmSgmMask0);
			BitBlt(	hdc,
				PosX, PosY,
				bm0.bmWidth, bm0.bmHeight,
				hdcMemory, 0, 0, SRCAND);

			SelectObject(hdcMemory, hbmSgmBlue);
			BitBlt(	hdc,
				PosX, PosY,
				bm0.bmWidth, bm0.bmHeight,
				hdcMemory, 0, 0, SRCPAINT);

			break;

		case 1:
			SelectObject(hdcMemory, hbmSgmMask1);
			BitBlt(	hdc,
				PosX, PosY,
				bm0.bmWidth, bm0.bmHeight,
				hdcMemory, 0, 0, SRCAND);

			SelectObject(hdcMemory, hbmSgmBlue);
			BitBlt(	hdc,
				PosX, PosY,
				bm0.bmWidth, bm0.bmHeight,
				hdcMemory, 0, 0, SRCPAINT);

			break;

		case 2:
			SelectObject(hdcMemory, hbmSgmMask2);
			BitBlt(	hdc,
				PosX, PosY,
				bm0.bmWidth, bm0.bmHeight,
				hdcMemory, 0, 0, SRCAND);

			SelectObject(hdcMemory, hbmSgmBlue);
			BitBlt(	hdc,
				PosX, PosY,
				bm0.bmWidth, bm0.bmHeight,
				hdcMemory, 0, 0, SRCPAINT);

			break;

		case 3:
			SelectObject(hdcMemory, hbmSgmMask3);
			BitBlt(	hdc,
				PosX, PosY,
				bm0.bmWidth, bm0.bmHeight,
				hdcMemory, 0, 0, SRCAND);

			SelectObject(hdcMemory, hbmSgmBlue);
			BitBlt(	hdc,
				PosX, PosY,
				bm0.bmWidth, bm0.bmHeight,
				hdcMemory, 0, 0, SRCPAINT);

			break;

		case 4:
			SelectObject(hdcMemory, hbmSgmMask4);
			BitBlt(	hdc,
				PosX, PosY,
				bm0.bmWidth, bm0.bmHeight,
				hdcMemory, 0, 0, SRCAND);
			SelectObject(hdcMemory, hbmSgmBlue);
			BitBlt(	hdc,
				PosX, PosY,
				bm0.bmWidth, bm0.bmHeight,
				hdcMemory, 0, 0, SRCPAINT);

			break;

		case 5:
			SelectObject(hdcMemory, hbmSgmMask5);
			BitBlt(	hdc,
				PosX, PosY,
				bm0.bmWidth, bm0.bmHeight,
				hdcMemory, 0, 0, SRCAND);

			SelectObject(hdcMemory, hbmSgmBlue);
			BitBlt(	hdc,
				PosX, PosY,
				bm0.bmWidth, bm0.bmHeight,
				hdcMemory, 0, 0, SRCPAINT);

			break;

		case 6:
			SelectObject(hdcMemory, hbmSgmMask6);
			BitBlt(	hdc,
				PosX, PosY,
				bm0.bmWidth, bm0.bmHeight,
				hdcMemory, 0, 0, SRCAND);

			SelectObject(hdcMemory, hbmSgmBlue);
			BitBlt(	hdc,
				PosX, PosY,
				bm0.bmWidth, bm0.bmHeight,
				hdcMemory, 0, 0, SRCPAINT);

			break;

		case 7:
			SelectObject(hdcMemory, hbmSgmMask7);
			BitBlt(	hdc,
				PosX, PosY,
				bm0.bmWidth, bm0.bmHeight,
				hdcMemory, 0, 0, SRCAND);

			SelectObject(hdcMemory, hbmSgmBlue);
			BitBlt(	hdc,
				PosX, PosY,
				bm0.bmWidth, bm0.bmHeight,
				hdcMemory, 0, 0, SRCPAINT);

			break;

		case 8:
			SelectObject(hdcMemory, hbmSgmMask8);
			BitBlt(	hdc,
				PosX, PosY,
				bm0.bmWidth, bm0.bmHeight,
				hdcMemory, 0, 0, SRCAND);

			SelectObject(hdcMemory, hbmSgmBlue);
			BitBlt(	hdc,
				PosX, PosY,
				bm0.bmWidth, bm0.bmHeight,
				hdcMemory, 0, 0, SRCPAINT);

			break;

		case 9:
			SelectObject(hdcMemory, hbmSgmMask9);
			BitBlt(	hdc,
				PosX, PosY,
				bm0.bmWidth, bm0.bmHeight,
				hdcMemory, 0, 0, SRCAND);
			SelectObject(hdcMemory, hbmSgmBlue);
			BitBlt(	hdc,
				PosX, PosY,
				bm0.bmWidth, bm0.bmHeight,
				hdcMemory, 0, 0, SRCPAINT);

			break;

		default: break;

	} //switch

	DeleteDC(hdcMemory);
	ReleaseDC(Hwnd, hdc);

} //UpdateDigit