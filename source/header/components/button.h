#ifndef BUTTON_H
#define BUTTON_H
#include <windows.h>
class Button {

public:
  Button();
  ~Button();
  LPCTSTR text;
  int width;
  int height;
  int x;
  int y;
  HWND button;
  void setText(LPCTSTR);
  void create(HINSTANCE, HWND);
  void setSize(int, int);
  void setPosition(int, int);
};
#endif
