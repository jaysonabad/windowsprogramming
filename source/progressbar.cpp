#include <bintana.h> // no need to call other header files since 'bintana.h' contains all needed files

ProgressBar::ProgressBar() {}

void ProgressBar::setText(LPCTSTR text){
  this->text = text;
}

void ProgressBar::setSize(int width, int height){
  this->width = width;
  this->height = height;
}

void ProgressBar::setPosition(int x, int y){
  this->x = x;
  this->y = y;
}

void ProgressBar::create(HINSTANCE hInstance, HWND parent, HMENU id){
  this->hwndComponent = CreateWindow(
    PROGRESS_CLASS,  // component type
    this->text,// label of the component
    WS_CHILD | WS_VISIBLE, // style of component
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

HWND ProgressBar::getHandle(){
  return this->hwndComponent;
}

ProgressBar::~ProgressBar() {}
