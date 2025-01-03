#ifndef FRAME_H
#define FRAME_H
#include <windows.h>

class Frame {

public:
  Frame();
  ~Frame();
  int width;
  int height;
  int x;
  int y;
  HWND hFrame;
  void setSize(int, int);
  void setPosition(int, int);
  void create(HINSTANCE, HWND, HMENU);
  HWND getHandle();
};
#endif
