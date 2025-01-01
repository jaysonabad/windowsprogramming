#define WINVER 0x0501
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

  this->button.setText("Noysoft");
  this->button.setSize(100, 100);
  this->button.setPosition(10, 10);
  this->button.create(hInstance, this->hWnd);

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

LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

    HDC hdc;
    PAINTSTRUCT ps;
    RECT aRect;

    switch (msg) {
      // to draw to the screen
      case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
        return 0;

      case WM_COMMAND:
        switch (wParam) {
          case BN_CLICKED:
            MessageBox( hWnd, "Start", "Message Box", MB_OK );
            break;
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
