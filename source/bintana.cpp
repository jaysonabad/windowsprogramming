#include <bintana.h> // no need to call other header files since 'bintana.h' contains all needed files

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK Window2Proc(HWND, UINT, WPARAM, LPARAM);
VOID CALLBACK TimerProc(HWND, UINT, UINT, DWORD);
BOOL CALLBACK DialogProc(HWND, UINT, WPARAM, LPARAM);
Button        button1;
Button        button2;
Frame         frame;
ComboBox      combox;
ProgressBar   progressbar;
WNDPROC       buttonProc;
HWND          hwndEdit;
HWND          hwndWindow2;
HWND          hwndDialog;

bool          windowclosed = false;
bool          endprogram = false;
HWND          handleTwo;

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

  WNDCLASSEX windowclass2;
  ZeroMemory(&windowclass2, sizeof(WNDCLASSEX));
  windowclass2.cbClsExtra = 0;
  windowclass2.cbSize = sizeof(WNDCLASSEX);
  windowclass2.cbWndExtra = 0;
  windowclass2.hbrBackground = static_cast<HBRUSH>(GetStockObject(GRAY_BRUSH));
  windowclass2.hCursor = LoadCursor(NULL, IDC_ARROW);
  windowclass2.hIcon = 0;
  windowclass2.hIconSm = 0;
  windowclass2.hInstance = hInstance;
  windowclass2.lpfnWndProc = (WNDPROC)Window2Proc;
  windowclass2.lpszClassName = "WindowClass2";
  windowclass2.lpszMenuName = NULL;
  windowclass2.style = CS_HREDRAW | CS_VREDRAW;

  if(!RegisterClassEx(&windowclass2)){
    int nResult = GetLastError();
    MessageBox(NULL, "Window Class Creation Failed", "Window Class Failed", MB_ICONERROR);
  }

  handleTwo = CreateWindowEx(
    0,
    windowclass2.lpszClassName,
    "Window Two",
    WS_CAPTION,
    200,
    150,
    640,
    480,
    0,
    0,
    hInstance,
    0
  );

  if(!handleTwo){
    int nResult = GetLastError();
    MessageBox(NULL, "Window 2 Creation Failed", "Window Creation Failed", MB_ICONERROR);
  }
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
  SendMessage(combox.getHandle(), CB_ADDSTRING, 0, (LPARAM) "Waking up the project.");
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

  hwndDialog = CreateDialog(hInstance, "MyDlgClass", NULL, DialogProc);
}

BOOL CALLBACK DialogProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
  switch(msg){
    case WM_INITDIALOG:
      ShowWindow(hwndDialog, SW_SHOW);
      return 0;
    case WM_DESTROY:
      EndDialog(hDlg, 0);
      return 0;
    }
  return 0;
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
    HBRUSH hbr;
    HICON hIcon;
    HWND icon_button;

    //SetTimer(hWnd,IDT_TIMER1, 500,(TIMERPROC)NULL);
    //SetTimer(hWnd,IDT_TIMER2, 1000, (TIMERPROC)NULL);

    switch (msg) {
      // to draw to the screen
      case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        aRect = {
          530, // x1
          130, // y1
          780, // x2
          380}; // y2
        hbr = CreateSolidBrush(RGB(125, 0, 0));
        FillRect(ps.hdc, &aRect, hbr);
        DeleteObject(hbr);
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
              ShowWindow(handleTwo, SW_SHOWNORMAL);
              UpdateWindow(handleTwo);
              //UpdateWindow(hwndWindow2);
              //ShowWindow(hwndEdit, SW_HIDE);
              return 0;
            case BUTTON2:
              //MessageBox(hWnd, "Button 2 Clicked", "Message Box", MB_OK );
              ShowWindow(frame.getHandle(), SW_SHOW);
              ShowWindow(hwndEdit, SW_SHOW);
              SendMessage(button2.getHandle(), WM_SETTEXT, 0, (LPARAM)"Hello");
              ShowWindow(hwndWindow2, SW_HIDE);
              ShowWindow(handleTwo, SW_HIDE);
              UpdateWindow(handleTwo);
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

LRESULT CALLBACK Window2Proc(HWND handleTwo, UINT msg, WPARAM wParam, LPARAM lParam){
  switch (msg) {
    case WM_DESTROY:
      MessageBox(
        NULL,
        "Window 1 closed",
        "Message",
        MB_ICONINFORMATION
      );
      windowclosed = true;
      return 0;
  }
  return DefWindowProc(handleTwo, msg, wParam, lParam);
}

void Bintana::Start(int nCmdShow) {
  MSG msg;
  ZeroMemory(&msg, sizeof(MSG));
  ShowWindow(this->hWnd, nCmdShow);
  UpdateWindow(this->hWnd);
  UpdateWindow(handleTwo);
  while(GetMessage(&msg, 0, 0, 0) == TRUE) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
    // Game Loop
  }
}

Bintana::~Bintana(){}
