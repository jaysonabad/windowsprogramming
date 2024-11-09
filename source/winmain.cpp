#include <windows.h>

#pragma args n used

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
    "Windows Programming",
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

  switch (msg) {
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
      EndPaint(hWnd, &sPaint);
      return 0;

    case WM_DESTROY:
      PostQuitMessage(WM_QUIT);
      return 0;
    default:
      return DefWindowProc(hWnd, msg, wParam, lParam);
  }
}
