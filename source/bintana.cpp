#include <bintana.h> // no need to call other header files since 'bintana.h' contains all needed files

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
VOID CALLBACK TimerProc(HWND, UINT, UINT, DWORD);
Button        button1;
Button        button2;
Frame         frame;
ComboBox      combox;
ProgressBar   progressbar;
WNDPROC       buttonProc;
HWND          hwndEdit;
HWND          hwndWindow2;

Bintana::Bintana(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  ZeroMemory(&this->wndw,sizeof(WNDCLASSEX));
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
  CreateMainWindow(hInstance);
  Components(hInstance);
  //SetTimer(hWnd,IDT_TIMER3, 5000, (TIMERPROC)TimerProc);
}

void Bintana::CreateMainWindow(HINSTANCE hInstance) {
  this->hWnd = CreateWindow(
    szAppName,
    "Test with class",
    WS_OVERLAPPEDWINDOW,
    80,
    20,
    1200,
    700,
    0,
    0,
    hInstance,
    0
  );
}

void Bintana::Components(HINSTANCE hInstance){
  frame.setSize(500, 400);
  frame.setPosition(10, 50);
  frame.create(NULL, hWnd, (HMENU)FRAME1);

  button1.setText("Noysoft");
  button1.setSize(100, 100);
  button1.setPosition(10, 50);
  button1.create(NULL, hWnd, (HMENU)BUTTON1);

  button2.setText("Button2");
  button2.setSize(100, 100);
  button2.setPosition(100, 50);
  button2.create(NULL, hWnd, (HMENU)BUTTON2);

  combox.setText("Rank");
  combox.setSize(200, 200);
  combox.setPosition(10, 10);
  combox.create(NULL, hWnd, (HMENU)COMBOX1);
  SendMessage(combox.getHandle(), CB_ADDSTRING, 0, (LPARAM) "S-Class");
  SendMessage(combox.getHandle(), CB_ADDSTRING, 0, (LPARAM) "A-Class");
  SendMessage(combox.getHandle(), CB_ADDSTRING, 0, (LPARAM) "B-Class");
  SendMessage(combox.getHandle(), CB_ADDSTRING, 0, (LPARAM) "C-Class");
  SendMessage(combox.getHandle(), CB_ADDSTRING, 0, (LPARAM) "D-Class");
  SendMessage(combox.getHandle(), CB_ADDSTRING, 0, (LPARAM) "E-CLass");
  SendMessage(combox.getHandle(), CB_ADDSTRING, 0, (LPARAM) "F-Class");
  // Default Item
  SendMessage(combox.getHandle(), CB_SETCURSEL, 2, 0);

  hwndEdit = CreateWindow(
    "edit",
    NULL,
    WS_BORDER|WS_CHILD|WS_VISIBLE|WS_HSCROLL|WS_VSCROLL|ES_MULTILINE|ES_AUTOHSCROLL,
    20, // x position
    170, // y position
    490, // button width
    290, // button height
    hWnd, // parent window
    (HMENU)EDIT_BOX1, // menu
    NULL, // hInstance
    NULL // pointer not needed
  );

  progressbar.setText("progressbar1");
  progressbar.setSize(200, 20);
  progressbar.setPosition(500, 500);
  progressbar.create(NULL, hWnd, (HMENU)PROGRESS_ID1);

  SendMessage(progressbar.getHandle(), PBM_DELTAPOS, 25, (LPARAM)"My Progress");
  SendMessage(progressbar.getHandle(), PBM_SETPOS, 50, (LPARAM)"My Progress");
  SendMessage(progressbar.getHandle(), PBM_SETSTEP, 1, (LPARAM)"My Progress");
  SendMessage(progressbar.getHandle(), PBM_STEPIT, (WPARAM)0, (LPARAM)"My Progress");
}

VOID CALLBACK TimerProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime){
  MessageBox(NULL, "Five seconds have passed," \
                    "the timer procedure is called," \
                    "killing the timer", "Timer procedure", MB_OK);
  KillTimer(hWnd, idEvent);
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static POINT apt[4];
    int cxClient, cyClient;
    HDC hdc;
    PAINTSTRUCT ps;
    RECT aRect;
    HICON hIcon;
    HWND icon_button;

    //SetTimer(hWnd,IDT_TIMER1, 500,(TIMERPROC)NULL);
    //SetTimer(hWnd,IDT_TIMER2, 1000, (TIMERPROC)NULL);

    switch (msg) {
      // to draw to the screen
      case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
        return 0;
      // Button events
      case WM_COMMAND:
        if((HIWORD(wParam) == BN_CLICKED) && (lParam != 0)) {
          switch(LOWORD(wParam)) {
            case BUTTON1:
              //MessageBox(frame.getHandle(), derive.printsomething(), "Message Box", MB_OK );
              ShowWindow(frame.getHandle(), SW_HIDE);
              ShowWindow(hwndWindow2, SW_SHOWNORMAL);
              //UpdateWindow(hwndWindow2);
              //ShowWindow(hwndEdit, SW_HIDE);
              return 0;
            case BUTTON2:
              //MessageBox(hWnd, "Button 2 Clicked", "Message Box", MB_OK );
              ShowWindow(frame.getHandle(), SW_SHOW);
              ShowWindow(hwndEdit, SW_SHOW);
              SendMessage(button2.getHandle(), WM_SETTEXT, 0, (LPARAM)"Hello");
              ShowWindow(hwndWindow2, SW_HIDE);
              //UpdateWindow(hwndWindow2);
              return 0;
          }
        }
        return 0;
      // Destroy the window
      case WM_TIMER:
        switch (wParam) {
          case IDT_TIMER1:
        //    ShowWindow(frame.getHandle(), SW_HIDE);
            return 0;
          case IDT_TIMER2:
        //    ShowWindow(frame.getHandle(), SW_SHOW);
            return 0;
          case IDT_TIMER3:
            return 0;
        }
      case WM_DESTROY:
        PostQuitMessage(WM_QUIT);
        return 0;
      default:
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }
    KillTimer(hWnd, IDT_TIMER1);
    KillTimer(hWnd, IDT_TIMER2);
    KillTimer(hWnd, IDT_TIMER3);
}

void Bintana::Start(int nCmdShow) {
  ShowWindow(this->hWnd, nCmdShow);
  UpdateWindow(this->hWnd);
  MSG msg;
  while(GetMessage(&msg, 0, 0, 0) == TRUE) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
    // Game Loop
  }
}

Bintana::~Bintana(){}
