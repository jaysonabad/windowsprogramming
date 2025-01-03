#include <windows.h>
#include <bintana.h>
#include <components/button.h>
#include <components/frame.h>

#define BUTTON1      1001
#define BUTTON2      1002
#define FRAME1       1003

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
  create(hInstance);
  components(hInstance);
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

void Bintana::create(HINSTANCE hInstance) {
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
}

void Bintana::components(HINSTANCE hInstance){
  frame.setSize(500, 400);
  frame.setPosition(10, 10);
  frame.create(hInstance, hWnd, (HMENU)FRAME1);

  button.setText("Noysoft");
  button.setSize(100, 100);
  button.setPosition(10, 10);
  button.create(hInstance, this->frame.getHandle(), (HMENU)BUTTON1);

  button.setText("Button2");
  button.setSize(100, 100);
  button.setPosition(200, 10);
  button.create(hInstance, hWnd, (HMENU)BUTTON2);
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static POINT apt[4];
    int cxClient, cyClient;
    HDC hdc;
    PAINTSTRUCT ps;
    RECT aRect;

    Frame frame;

    switch (msg) {
      // to draw to the screen
      case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
        return 0;
      case WM_COMMAND:
        if((HIWORD(wParam) == BN_CLICKED) && (lParam != 0)) {
          switch(LOWORD(wParam)) {
            case BUTTON1:
              MessageBox(frame.getHandle(), "Button 1 Clicked", "Message Box", MB_OK );
              ShowWindow(frame.getHandle(), SW_HIDE);
              return 0;
            case BUTTON2:
              MessageBox(hWnd, "Button 2 Clicked", "Message Box", MB_OK );
              return 0;
          }
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
