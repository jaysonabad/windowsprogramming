#include <bintana.h> // no need to call other header files since 'bintana.h' contains all needed files

ComboBox::ComboBox(){}

void ComboBox::setText(LPCTSTR text) {
  this->text = text;
}

void ComboBox::setSize(int width, int height){
  this->width = width;
  this->height = height;
}

void ComboBox::setPosition(int x, int y){
  this->x = x;
  this->y = y;
}

void ComboBox::create(HINSTANCE hInstance, HWND parent, HMENU id){
  this->hwndComponent = CreateWindow(
    "combobox", // component type
    this->text, // label of the component
    WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, // style of component
    this->x, // x position of component
    this->y, // y position of component
    this->width, // width of the component
    this->height, // height of the component
    parent, // parent window
    id, // menu id
    hInstance, // component instance that handle to the window
    NULL // pointer
  );
}

HWND ComboBox::getHandle(){
  return this->hwndComponent;
}

ComboBox::~ComboBox(){}
