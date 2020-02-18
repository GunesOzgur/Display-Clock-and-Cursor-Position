// Winmain.c

#include "SystemClock.h"
#include <time.h>

const int posX = 15;
const int posY = 15;
const int posY2 = 250;

const UINT timerID_1 = 1;
UINT timerDelay = 1000;

UINT counter = 0;

time_t rawtime;
struct tm *timeinfo;

UINT hour10_x	= 15;
UINT hour1_x	= 15 + 59;
UINT colon1_x	= 15 + (59*2);
UINT min10_x	= 15 + (59*3);
UINT min1_x	= 15 + (59*4);
UINT colon2_x	= 15 + (59*5);
UINT sec10_x	= 15 + (59*6);
UINT sec1_x	= 15 + (59*7);

UINT curPosX3	= 15;
UINT curPosX2	= 15 + 59;
UINT curPosX1	= 15 + (59*2);
UINT curPosX0	= 15 + (59*3);
UINT curPosY3	= 15 + (59*5);
UINT curPosY2	= 15 + (59*6);
UINT curPosY1	= 15 + (59*7);
UINT curPosY0	= 15 + (59*8);

POINT p;

LRESULT CALLBACK WndProc( HWND hwnd,
			  UINT Message,
			  WPARAM wParam,
			  LPARAM lParam )
{
   switch(Message) {

      case WM_CREATE:

         hbmSgmBlue = LoadBitmap(Wnd_hInst, "SGM_BLUE_BMP");

         hbmSgmMask0 = LoadBitmap(Wnd_hInst, "SGM_MASK0_BMP");
         hbmSgmMask1 = LoadBitmap(Wnd_hInst, "SGM_MASK1_BMP");
         hbmSgmMask2 = LoadBitmap(Wnd_hInst, "SGM_MASK2_BMP");
         hbmSgmMask3 = LoadBitmap(Wnd_hInst, "SGM_MASK3_BMP");
         hbmSgmMask4 = LoadBitmap(Wnd_hInst, "SGM_MASK4_BMP");
         hbmSgmMask5 = LoadBitmap(Wnd_hInst, "SGM_MASK5_BMP");
         hbmSgmMask6 = LoadBitmap(Wnd_hInst, "SGM_MASK6_BMP");
         hbmSgmMask7 = LoadBitmap(Wnd_hInst, "SGM_MASK7_BMP");
         hbmSgmMask8 = LoadBitmap(Wnd_hInst, "SGM_MASK8_BMP");
         hbmSgmMask9 = LoadBitmap(Wnd_hInst, "SGM_MASK9_BMP");

         hbmSgmColon = LoadBitmap(Wnd_hInst, "SGM_COLON_BMP");

         if( !hbmSgmBlue
             || !hbmSgmMask0
             || !hbmSgmMask1
             || !hbmSgmMask2
             || !hbmSgmMask3
             || !hbmSgmMask4
             || !hbmSgmMask5
             || !hbmSgmMask6
             || !hbmSgmMask7
             || !hbmSgmMask8
             || !hbmSgmMask9
             || !hbmSgmColon ) {

				MessageBox(	hwnd,
						"Load of resources failed.",
						"Error",
						MB_OK | MB_ICONEXCLAMATION );
				return -1;
			}

			GetObject(hbmSgmMask0, sizeof(bm0), &bm0);

			SetTimer(hwnd, timerID_1, timerDelay, NULL);

			break;

		case WM_PAINT:

			if(	hbmSgmBlue
				&& hbmSgmMask0
				&& hbmSgmMask1
				&& hbmSgmMask2
				&& hbmSgmMask3
				&& hbmSgmMask4
				&& hbmSgmMask5
				&& hbmSgmMask6
				&& hbmSgmMask7
				&& hbmSgmMask8
				&& hbmSgmMask9 ) {

				PAINTSTRUCT ps;
            			HDC hdcWindow;
            			hdcWindow = BeginPaint(hwnd, &ps);

				DrawDigit(hdcWindow, 10, colon1_x, posY);
				DrawDigit(hdcWindow, 10, colon2_x, posY);

				EndPaint(hwnd, &ps);
			}

			break;

		case WM_TIMER:

			time(&rawtime);
			timeinfo = localtime(&rawtime);

			UpdateDigit(	hwnd,
					hour10_x, posY,
					(timeinfo->tm_hour)/10 );

			UpdateDigit(	hwnd,
					hour1_x, posY,
					(timeinfo->tm_hour)%10 );

			UpdateDigit(	hwnd,
					min10_x, posY,
					(timeinfo->tm_min)/10 );

			UpdateDigit(	hwnd,
					min1_x, posY,
					(timeinfo->tm_min)%10 );

			UpdateDigit(	hwnd,
					sec10_x, posY,
					(timeinfo->tm_sec)/10 );

			UpdateDigit(	hwnd,
					sec1_x, posY,
					(timeinfo->tm_sec)%10 );

			/*PlaySound("Sine1000Hz.wav", GetModuleHandle(NULL),
				SND_FILENAME | SND_ASYNC | SND_NOSTOP );*/
			break;

		case WM_MOUSEMOVE:

			GetCursorPos(&p);
			ScreenToClient(hwnd, &p);

			UpdateDigit(	hwnd,
					curPosX3, posY2,
					(int)((p.x)/1000) );

			UpdateDigit(	hwnd,
					curPosX2, posY2,
					(int)(((p.x)/100)%10) );

			UpdateDigit(	hwnd,
					curPosX1, posY2,
					(int)(((p.x)%100)/10) );

			UpdateDigit(	hwnd,
					curPosX0, posY2,
					(int)((p.x)%10) );

			UpdateDigit(	hwnd,
					curPosY3, posY2,
					(int)((p.y)/1000) );

			UpdateDigit(	hwnd,
					curPosY2, posY2,
					(int)(((p.y)/100)%10) );

			UpdateDigit(	hwnd,
					curPosY1, posY2,
					(int)(((p.y)%100)/10) );

			UpdateDigit(	hwnd,
					curPosY0, posY2,
					(int)((p.y)%10) );

			break;

		case WM_DESTROY:

			KillTimer(hwnd, timerID_1);

			DeleteObject(hbmSgmBlue);
			DeleteObject(hbmSgmMask0);
			DeleteObject(hbmSgmMask1);
			DeleteObject(hbmSgmMask2);
			DeleteObject(hbmSgmMask3);
			DeleteObject(hbmSgmMask4);
			DeleteObject(hbmSgmMask5);
			DeleteObject(hbmSgmMask6);
			DeleteObject(hbmSgmMask7);
			DeleteObject(hbmSgmMask8);
			DeleteObject(hbmSgmMask9);

			PostQuitMessage(0);
			break;

		default: return DefWindowProc(hwnd, Message, wParam, lParam);
	}

	return 0;
}

int WINAPI WinMain(	HINSTANCE hInstance,
			HINSTANCE hPrevInstance,
			LPSTR lpCmdLine,
			int nCmdShow )
{
	WNDCLASSEX WndClass;
	HWND Hwnd;
	MSG Msg;

	Wnd_hInst = hInstance;

	WndClass.cbSize        = sizeof(WNDCLASSEX);
	WndClass.style         = 0;
	WndClass.lpfnWndProc   = WndProc;
	WndClass.cbClsExtra    = 0;
	WndClass.cbWndExtra    = 0;
	WndClass.hInstance     = Wnd_hInst;
	WndClass.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor       = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = Wnd_bg;
	WndClass.lpszMenuName  = NULL;
	WndClass.lpszClassName = Wnd_szClassName;
	WndClass.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&WndClass)) {

		MessageBox(0, "Window Registration Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK | MB_SYSTEMMODAL);
		return 0;
	}

	//PlaySound("Sine1000hz-1s.wav", GetModuleHandle(NULL),
	//			SND_FILENAME | SND_ASYNC );

	Hwnd = CreateWindowEx(	WS_EX_CLIENTEDGE,
				Wnd_szClassName,
				"System Clock",
				WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, CW_USEDEFAULT,
				700, 500,
				NULL, NULL, Wnd_hInst, NULL);

	if(Hwnd == NULL) {
      
		MessageBox(	0,
				"Window Creation Failed!",
				"Error!",
				MB_ICONEXCLAMATION | MB_OK | MB_SYSTEMMODAL);
		return 0;
	}

	ShowWindow(Hwnd, nCmdShow);
	UpdateWindow(Hwnd);

	while(GetMessage(&Msg, NULL, 0, 0)) {
      
	TranslateMessage(&Msg);
	DispatchMessage(&Msg);
	}

	return Msg.wParam;
}