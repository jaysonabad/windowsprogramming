#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>
#include <components/button.h>
#include <components/frame.h>

class Bintana {

public:
  Bintana(HINSTANCE, HINSTANCE, LPSTR, int);
  ~Bintana();

  LPCTSTR szAppName;
  HINSTANCE hInstance;
  WNDCLASSEX wndw;
  HWND hWnd;
  MSG msg;

  Button button;
  Frame frame;

  void start(int);
  void create(HINSTANCE);
  void components(HINSTANCE);
};

#endif
