#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>
#pragma args n used

class Bintana {

public:
  Bintana(HINSTANCE, HINSTANCE, LPSTR, int);
  ~Bintana();
  LPCTSTR szAppName;
  WNDCLASSEX wndw;
  HWND hWnd;
  HWND hwndbutton;
  MSG msg;

  void windowloop(int);

};

#endif
