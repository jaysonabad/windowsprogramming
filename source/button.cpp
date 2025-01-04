#include <windows.h>
#include <components/button.h>

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
  this->hwndButton = CreateWindow(
    "button",
    this->text,
    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
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

HWND Button::getHandle() {
  return this->hwndButton;
}

Button::~Button(){}
