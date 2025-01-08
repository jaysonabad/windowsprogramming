#ifndef COMBOBOX_H
#define COMBOBOX_H
#include <windows.h>
#include <components.h>

class ComboBox : public Components{

public:
  ComboBox();
  ~ComboBox();
  void setText(LPCTSTR) override;
  void setSize(int, int) override;
  void setPosition(int, int) override;
  void create(HINSTANCE, HWND, HMENU) override;
  HWND getHandle() override;
};

#endif
