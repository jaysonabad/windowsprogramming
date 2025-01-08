#include <bintana.h> // no need to call other header files since 'bintana.h' contains all needed files

Frame::Frame(){}

void Frame::setText(LPCTSTR text) {
  this->text = text;
}

void Frame::setSize(int width, int height){
  this->width = width;
  this->height = height;
}
void Frame::setPosition(int x, int y) {
  this->x = x;
  this->y = y;
}
void Frame::create(HINSTANCE hInstance, HWND parent, HMENU id) {
  this->hwndComponent = CreateWindow(
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
  return this->hwndComponent;
}
Frame::~Frame(){}
