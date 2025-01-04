#ifndef DERIVE_H
#define DERIVE_H
#include <windows.h>

#include <components.h>

class Derive : public Components {

public:
  Derive();
  ~Derive();
  LPCTSTR printsomething() override;
};

#endif
