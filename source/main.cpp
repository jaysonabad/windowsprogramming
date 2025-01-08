#define WIN32_LEAN_AND_MEAN
#include <bintana.h>
#pragma args n used

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

  Bintana bintana(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
  bintana.start(nCmdShow);

  return 0;
}
