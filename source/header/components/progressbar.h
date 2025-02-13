#ifndef PROGRESSBAR_H
#define PROGRESBAR_H
#include <windows.h>
#include <components/components.h>

class ProgressBar : protected Components {

public:
  ProgressBar();
  ~ProgressBar();
  void setText(LPCTSTR) override;
  void setSize(int, int) override;
  void setPosition(int, int) override;
  void create(HINSTANCE, HWND, HMENU) override;
  HWND getHandle() override;
};

#endif
