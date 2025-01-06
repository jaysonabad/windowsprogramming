#ifndef BUTTON_H
#define BUTTON_H
#include <windows.h>
#include <components/components.h>

class Button : public Components {
public:
  Button();
  ~Button();
  LPCTSTR text;
  int width;
  int height;
  int x;
  int y;
  HWND hwndButton;
  void setText(LPCTSTR) override;
  void setSize(int, int) override;
  void setPosition(int, int) override;
  void create(HINSTANCE, HWND, HMENU) override;
  HWND getHandle() override;
};
#endif
