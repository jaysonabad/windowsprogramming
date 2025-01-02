#define BUTTON1      1001
#define BUTTON2      1002

#include <windows.h>
#include <bintana.h>
#include <components/button.h>
#pragma args n used

LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

Bintana::Bintana(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

  this->szAppName = "WindowsProgramming";
  this->wndw.cbSize = sizeof(WNDCLASSEX);
  this->wndw.style = CS_HREDRAW | CS_VREDRAW;
  this->wndw.lpfnWndProc = WindowProc;
  this->wndw.cbClsExtra = 0;
  this->wndw.cbWndExtra = 0;
  this->wndw.hInstance = hInstance;
  this->wndw.hIcon = LoadIcon(0, IDI_APPLICATION);
  this->wndw.hCursor = LoadCursor(0, IDC_ARROW);
  this->wndw.hbrBackground = static_cast<HBRUSH>(GetStockObject(GRAY_BRUSH));
  this->wndw.lpszMenuName = 0;
  this->wndw.lpszClassName = this->szAppName;
  this->wndw.hIconSm = 0;

  RegisterClassEx(&wndw);

  this->hWnd = CreateWindow(
    szAppName,
    "Test with class",
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    1200,
    700,
    0,
    0,
    hInstance,
    0
  );

  // window layouts
  // HWND frame;
  //
  // frame = CreateWindow(
  //   "SURFACE",
  //   NULL,
  //   WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
  //   10, // x position
  //   10, // y position
  //   500, // button width
  //   300, // button height
  //   this->hWnd, // parent window
  //   NULL, // no menu
  //   hInstance,
  //   NULL // pointer not needed
  // );

  // this->button.setText("Noysoft");
  // this->button.setSize(100, 100);
  // this->button.setPosition(10, 10);
  // this->button.create(hInstance, this->hWnd, (HMENU)BUTTON1);
  //
  // this->button.setText("Button2");
  // this->button.setSize(100, 100);
  // this->button.setPosition(200, 10);
  // this->button.create(hInstance, this->hWnd, (HMENU)BUTTON2);

}

void Bintana::start(int nCmdShow) {
  ShowWindow(this->hWnd, nCmdShow);
  UpdateWindow(this->hWnd);

  MSG msg;
  while(GetMessage(&msg, 0, 0, 0) == TRUE) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
}

void DrawBezier(HDC hdc, POINT apt[]) {
  PolyBezier(hdc, apt, 4);
  MoveToEx(hdc, apt[0].x, apt[0].y, NULL);
  LineTo(hdc, apt[1].x, apt[1].y);
  MoveToEx(hdc, apt[2].x, apt[2].y, NULL);
  LineTo(hdc, apt[3].x, apt[3].y);

}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

    static POINT apt[4];
    int cxClient, cyClient;
    HDC hdc;
    PAINTSTRUCT ps;
    RECT aRect;

    switch (msg) {
      // to draw to the screen
      case WM_SIZE:
        cxClient = LOWORD(lParam);
        cyClient = HIWORD(lParam);
        apt[0].x = cxClient / 4;
        apt[0].y = cyClient / 2;

        apt[1].x = cxClient / 4;
        apt[1].y = cyClient / 2;

        apt[2].x = cxClient / 4;
        apt[2].y = 3 * cyClient / 2;

        apt[3].x = 3 * cxClient / 4;
        apt[3].y = cyClient / 2;
        
        return 0;

      case WM_LBUTTONDOWN:
      case WM_RBUTTONDOWN:
      case WM_MOUSEMOVE:
        if(wParam & MK_LBUTTON || wParam & MK_RBUTTON) {
          hdc = GetDC(hWnd);
          SelectObject(hdc, GetStockObject(WHITE_PEN));
          DrawBezier(hdc, apt);
          if(wParam & MK_LBUTTON) {
            apt[1].x = LOWORD(lParam);
            apt[1].y = HIWORD(lParam);
          }
          if(wParam & MK_RBUTTON) {
            apt[2].x = LOWORD(lParam);
            apt[2].y = HIWORD(lParam);
          }
          SelectObject(hdc, GetStockObject(BLACK_PEN));
          DrawBezier(hdc, apt);
          ReleaseDC(hWnd, hdc);
        }
        return 0;

      case WM_PAINT:
        InvalidateRect(hWnd, NULL, TRUE);

        hdc = BeginPaint(hWnd, &ps);
        DrawBezier(hdc, apt);

        EndPaint(hWnd, &ps);
        return 0;

      case WM_COMMAND:
        switch (HIWORD(wParam)) {
          case BN_CLICKED:
            if(LOWORD(wParam) == BUTTON1){
              MessageBox(hWnd, "Button 1 Clicked", "Message Box", MB_OK );
              return 0;
            }
            if(LOWORD(wParam) == BUTTON2){
              MessageBox(hWnd, "Button 2 Clicked", "Message Box", MB_OK );
              return 0;
            }
            return 0;
        }
        return 0;
      case WM_DESTROY:
        PostQuitMessage(WM_QUIT);
        return 0;
      default:
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }
}

Bintana::~Bintana(){}
