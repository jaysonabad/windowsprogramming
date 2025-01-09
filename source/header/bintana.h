#ifndef WINDOW_H
#define WINDOW_H
// Windows Header Files
#include <windows.h>
#include <commctrl.h>
// Bintana Library Header Files
#include <components/button.h>
#include <components/combobox.h>
#include <components/frame.h>
#include <components/progressbar.h>
// Defined Components IDs
#define BUTTON1      1001
#define BUTTON2      1002
#define BUTTON3      1004
#define FRAME1       1100
#define COMBOX1      1300
#define EDIT_BOX1    1200
#define IDT_TIMER1   1201
#define IDT_TIMER2   1202
#define IDT_TIMER3   1203
#define PROGRESS_ID1 1400

class Bintana {

private:
  LPCTSTR      szAppName;
  HINSTANCE    hInstance;
  WNDCLASSEX   wndw;
  HWND         hWnd;
  MSG          msg;

public:
  Bintana(HINSTANCE, HINSTANCE, LPSTR, int);
  ~Bintana();
  void Start(int);
  void CreateMainWindow(HINSTANCE);
  void Components(HINSTANCE);
};

#endif
