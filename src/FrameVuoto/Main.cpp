#include "Frame.h"
#include "form.h"
#include <FL/Fl.H>

extern Frame *scene;

//-------------------------------------------------------------------------------------------------
void idle_cb(void *) { scene->redraw(); }
//-------------------------------------------------------------------------------------------------
int main(int argc, char **argv) {
  CreateMyWindow();
  Fl::add_idle(idle_cb, 0);
  Fl::run();
  return 0;
}
//-------------------------------------------------------------------------------------------------
