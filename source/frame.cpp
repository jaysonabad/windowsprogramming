#include <windows.h>
#include <components/frame.h>

#define BUTTON1      1001
#define BUTTON2      1002
#define FRAME1       1003

Frame::Frame(){}

void Frame::setSize(int width, int height){
  this->width = width;
  this->height = height;
}
void Frame::setPosition(int x, int y) {
  this->x = x;
  this->y = y;
}
void Frame::create(HINSTANCE hInstance, HWND parent, HMENU id) {
  this->hwndFrame = CreateWindow(
    "static",
    NULL,
    WS_CHILD | WS_VISIBLE,
    this->x, // x position
    this->y, // y position
    this->width, // button width
    this->height, // button height
    parent, // parent window
    id, // menu
    hInstance,
    NULL // pointer not needed
  );
}
HWND Frame::getHandle(){
  return this->hwndFrame;
}
Frame::~Frame(){}
