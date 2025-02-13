#include <bintana.h> // no need to call other header files since 'bintana.h' contains all needed files

Button::Button(){}
void Button::setText(LPCTSTR text) {
  this->text = text;
}
void Button::setSize(int width, int height) {
  this->width = width;
  this->height = height;
}
void Button::setPosition(int x, int y) {
  this->x = x;
  this->y = y;
}

void Button::create(HINSTANCE hInstance, HWND parent, HMENU id) {
  this->hwndComponent = CreateWindow(
    "button", // component type
    this->text, // label of the component
    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, // style of component
    this->x, // x position
    this->y, // y position
    this->width, // width of the component
    this->height, // height of the component
    parent, // parent window
    id, // menu id
    hInstance, // component instance that handle to the window
    NULL // pointer
  );
}

HWND Button::getHandle() {
  return this->hwndComponent;
}

Button::~Button(){}
