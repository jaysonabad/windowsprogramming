#ifndef FRAME_H
#define FRAME_H
#include <windows.h>
#include <components/components.h>

class Frame : protected Components{

public:
  Frame();
  ~Frame();
  void setText(LPCTSTR) override;
  void setSize(int, int) override;
  void setPosition(int, int) override;
  void create(HINSTANCE, HWND, HMENU) override;
  HWND getHandle() override;
};
#endif
