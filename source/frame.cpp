#include <windows.h>
#include <components/frame.h>

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
  this->frame = CreateWindow(
    "static",
    NULL,
    WS_CHILD | WS_VISIBLE,
    this->x,
    this->y,
    this->width,
    this->height,
    parent,
    id,
    hInstance,
    NULL
  );
}
Frame::~Frame(){}
