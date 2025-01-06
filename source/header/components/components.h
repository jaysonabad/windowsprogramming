#ifndef COMPONENTS_H
#define COMPONENTS_H
#include <windows.h>

class Components{

public:
  Components();
  ~Components();
  virtual void setText(LPCTSTR);
  virtual void setSize(int, int);
  virtual void setPosition(int, int);
  virtual void create(HINSTANCE, HWND, HMENU);
  virtual HWND getHandle() = 0;
};

#endif
