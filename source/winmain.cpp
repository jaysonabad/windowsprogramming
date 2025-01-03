#include <windows.h>
#include <test.h>

Test test;

LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  // Register the window class
  static LPCTSTR szAppName = "WindowsProgramming";
  WNDCLASSEX window;
  window.cbSize = sizeof(WNDCLASSEX);
  window.style = CS_HREDRAW | CS_VREDRAW;
  window.lpfnWndProc = WindowProc;
  window.cbClsExtra = 0;
  window.cbWndExtra = 0;
  window.hInstance = hInstance;
  window.hIcon = LoadIcon(0, IDI_APPLICATION);
  window.hCursor = LoadCursor(0, IDC_ARROW);
  window.hbrBackground = static_cast<HBRUSH>(GetStockObject(GRAY_BRUSH));
  window.lpszMenuName = 0;
  window.lpszClassName = szAppName;
  window.hIconSm = 0;

  RegisterClassEx(&window);

  // Create the window

  HWND hWnd;
  hWnd = CreateWindow(
    szAppName,
    test.message(),
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    0,
    0,
    hInstance,
    0
  );

  HWND hwndbutton;
  hwndbutton = CreateWindow(
    "BUTTON",
    "OK",
    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
    10, // x position
    10, // y position
    100, // button width
    100, // button height
    hWnd, // parent window
    NULL, // no menu
    hInstance,
    NULL // pointer not needed
  );

  // Check the window handle value

  if(hWnd == NULL) {
    return 0;
  }

  // Show the window
  ShowWindow(hWnd, nCmdShow);
  UpdateWindow(hWnd);

  MSG msg;
  while(GetMessage(&msg, 0, 0, 0) == TRUE) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  return 0;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

  HDC hDC;
  PAINTSTRUCT sPaint;
  RECT aRect;

  int wmId, wmEvent;

  switch (msg) {
    case WM_COMMAND:
      wmId = LOWORD(wParam);
      wmEvent = HIWORD(wParam);
      switch (wmId) {
        case IDM_ABOUT:
          DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
          break;
        case IDM_EXIT:
          DestroyWindow(hWnd);
          break;
        default:
          return DefWindowProc(hWnd, message, wParam, lParam);
      }
      break;
    case WM_PAINT:
      hDC = BeginPaint(hWnd, &sPaint);
      GetClientRect(hWnd, &aRect);
      SetBkMode(hDC, TRANSPARENT);
      DrawText(
        hDC,
        "Hello, Windows!",
        -1,
        &aRect,
        DT_SINGLELINE | DT_CENTER | DT_VCENTER
      );

      TRIVERTEX vertex[3];
      vertex[0].x = 150;
      vertex[0].y = 0;
      vertex[0].Red = 0xff00;
      vertex[0].Green = 0x8000;
      vertex[0].Blue = 0x0000;
      vertex[0].Alpha = 0x0000;

      vertex[0].x = 0;
      vertex[0].y = 150;
      vertex[0].Red = 0x9000;
      vertex[0].Green = 0x0000;
      vertex[0].Blue = 0x9000;
      vertex[0].Alpha = 0x0000;

      vertex[0].x = 300;
      vertex[0].y = 150;
      vertex[0].Red = 0x9000;
      vertex[0].Green = 0x0000;
      vertex[0].Blue = 0x9000;
      vertex[0].Alpha = 0x0000;

      GRADIENT_TRIANGLE gTriangle;
      gTriangle.Vertex1 = 0;
      gTriangle.Vertex2 = 1;
      gTriangle.Vertex3 = 2;

      GradientFill(hdc, vertex, 3, &gTriangle, 1, GRADIENT_FILL_TRIANGLE);
      EndPaint(hWnd, &sPaint);
      break;

    case WM_DESTROY:
      PostQuitMessage(WM_QUIT);
      return 0;
    default:
      return DefWindowProc(hWnd, msg, wParam, lParam);
  }
}
