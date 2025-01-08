#ifndef BUTTON_H
#define BUTTON_H
#include <windows.h>
#include <components/components.h>

class Button : protected Components {
public:
  Button();
  ~Button();
  void setText(LPCTSTR) override;
  void setSize(int, int) override;
  void setPosition(int, int) override;
  void create(HINSTANCE, HWND, HMENU) override;
  HWND getHandle() override;
};
#endif
