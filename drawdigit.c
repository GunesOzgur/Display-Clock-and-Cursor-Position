/*
* drawdigit.c
*
* contains drawdigit() function definition
*
* External Variables:
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

void DrawDigit(HDC hdc, int digit, int PosX, int PosY)
{
	HDC hdcMemory;
	hdcMemory = CreateCompatibleDC(hdc);

	switch(digit) {

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

		case 10:
			SelectObject(hdcMemory, hbmSgmColon);
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
	}

	DeleteDC(hdcMemory);
}