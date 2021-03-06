
#include "Frame.h"

//-------------------------------------------------------------------------------------------------
void Frame::init() { draw_init(); }
//-------------------------------------------------------------------------------------------------
void Frame::draw() {
  if (!valid()) {
    glClearColor(0.0, 0.0, 0.0, 1); // Turn the background color black
    glViewport(0, 0, w(), h());     // Make our viewport the whole window
    glMatrixMode(GL_PROJECTION);    // Select The Projection Matrix
    glLoadIdentity();               // Reset The Projection Matrix
    gluPerspective(45.0f, w() / h(), 1, 150.0f);
    glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
    glLoadIdentity();           // Reset The Modelview Matrix
    glClear(GL_COLOR_BUFFER_BIT |
            GL_DEPTH_BUFFER_BIT); // Clear The Screen And The Depth Buffer
    glLoadIdentity();             // Reset The View
    gluLookAt(0, 0, 13, 0, 0, 0, 0, 1, 0); // Position - View  - Up Vector
    glEnable(GL_DEPTH_TEST);

    init();
    valid(1);
  }

  draw_scene();
}
