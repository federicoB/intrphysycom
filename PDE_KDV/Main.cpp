#include <stdio.h>
#include <FL/Fl.H>
#include "guicon.h"
#include "form.h"
#include "frame_1.h"

extern Frame_1   *scene;
//-------------------------------------------------------------------------------------------------
void idle_cb(void*)
{
  scene->redraw();    
}
// ********************************************************************************************************
int main(int argc, char **argv) {
  RedirectIOToConsole();
  CreateMyWindow();
  Fl::add_idle(idle_cb, 0);
  Fl::run();
  return 0;
}
// ********************************************************************************************************
