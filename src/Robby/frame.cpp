#include "frame.h"
#include "draw.h"
#include "includes.h"
#include <FL/Fl.H>
#include <FL/Fl_Output.H>
#include <FL/gl.h>
#include <FL/glu.h>

//-------------------------------------------------------------------------------------------------
void Frame::draw() {
  if (!valid()) {

    glClearColor(0.0, 0.0, 0.0, 1); // Turn the background color black
    glViewport(0, 0, w(), h());     // Make our viewport the whole window
    glMatrixMode(GL_PROJECTION);    // Select The Projection Matrix
    glLoadIdentity();               // Reset The Projection Matrix
    gluOrtho2D(-1.0, 101.0, -1.0, 101.0);
    glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
    glLoadIdentity();           // Reset The Modelview Matrix
    glClear(GL_COLOR_BUFFER_BIT |
            GL_DEPTH_BUFFER_BIT); // Clear The Screen And The Depth Buffer
    glLoadIdentity();             // Reset The View
    glEnable(GL_DEPTH_TEST);
    draw_init();
    valid(1);
  }
  draw_scene();
}
//-------------------------------------------------------------------------------------------------
