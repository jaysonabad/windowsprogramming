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
  HWND hButton;
  void setText(LPCTSTR);
  void setSize(int, int);
  void setPosition(int, int);
  void create(HINSTANCE, HWND, HMENU);
  HWND getHandle();
};
#endif
