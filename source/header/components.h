#ifndef COMPONENTS_H
#define COMPONENTS_H
#include <windows.h>

class Components{

public:
  Components();
  ~Components();
  virtual LPCTSTR printsomething() = 0;
};

#endif
