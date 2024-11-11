#include <windows.h>
#include <bintana.h>
#pragma args n used

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

  Bintana bintana(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
  bintana.windowloop(nCmdShow);

  return 0;
}
