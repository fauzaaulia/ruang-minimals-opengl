// ----------------------------------------------------------
// Includes
// ----------------------------------------------------------
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// ----------------------------------------------------------
// Function Prototypes
// ----------------------------------------------------------
void display();
void specialKeys();

// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------
double rotate_y=0;
double rotate_x=0;
int buka = 0;
int sudut = 0;
// ----------------------------------------------------------
// display() Callback function
// ----------------------------------------------------------
void bukapintu(){
    glTranslatef(0.3, -0.5, 0.5);
    glRotatef(-sudut, 0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
      glColor3ub(255, 106, 0);
      glVertex3f( 0.0, 0.0, 0.0 );
      glVertex3f( 0.0,  0.6, 0.0 );
      glVertex3f( -0.3, 0.6, 0.0 );
      glVertex3f( -0.3, 0.0, 0.0 );
    glEnd();
    glRotatef(sudut, 0.0, 1.0, 0.0);
    glTranslatef(-0.3, 0.5, -0.5);
}

void display(){

  //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  // Reset transformations
  glLoadIdentity();

  // Other Transformations
  // glTranslatef( 0.1, 0.0, 0.0 );      // Not included
  // glRotatef( 180, 0.0, 1.0, 0.0 );    // Not included

  // Rotate when user changes rotate_x and rotate_y
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );

  // Other Transformations
  // glScalef( 2.0, 2.0, 0.0 );          // Not included

  //Multi-colored side - FRONT
  //glBegin(GL_POLYGON);

  //glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(  0.5, -0.5, -0.5 );      // P1 is red
  //glColor3f( 0.0, 1.0, 0.0 );     glVertex3f(  0.5,  0.5, -0.5 );      // P2 is green
  //glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( -0.5,  0.5, -0.5 );      // P3 is blue
  //glColor3f( 1.0, 0.0, 1.0 );     glVertex3f( -0.5, -0.5, -0.5 );      // P4 is purple

  //glEnd();

  // Dinding Kiri
  glBegin(GL_POLYGON);
  glColor3ub(255, 125, 185);
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  // Lantai
  glBegin(GL_POLYGON);
  glColor3f(   0.8,  0.6,  0.4 );
  glVertex3f(  0.5, -0.5, -0.5 );
  glVertex3f(  0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  // Dinding Belakang sisi kiri
  glBegin(GL_POLYGON);
  glColor3ub(5, 140, 250);
  glVertex3f( -0.3, -0.5, 0.5 );
  glVertex3f( -0.3,  0.5, 0.5 );
  glVertex3f( -0.5,  0.5, 0.5 );
  glVertex3f( -0.5, -0.5, 0.5 );
  glEnd();

  // Dinding Belakang sisi kiri tengah atas
  glBegin(GL_POLYGON);
  glColor3ub(5, 140, 250);
  glVertex3f( -0.3,  0.2, 0.5 );
  glVertex3f( -0.3,  0.5, 0.5 );
  glVertex3f( -0.12, 0.5, 0.5 );
  glVertex3f( -0.12, 0.2, 0.5 );
  glEnd();

  // Dinding Belakang sisi kiri tengah bawah
  glBegin(GL_POLYGON);
  glColor3ub(5, 140, 250);
  glVertex3f( -0.3,  -0.2, 0.5 );
  glVertex3f( -0.3,  -0.5, 0.5 );
  glVertex3f( -0.12, -0.5, 0.5 );
  glVertex3f( -0.12, -0.2, 0.5 );
  glEnd();

  // Dinding Belakang sisi tengah
  glBegin(GL_POLYGON);
  glColor3ub(5, 140, 250);
  glVertex3f(  0.0, -0.5, 0.5 );
  glVertex3f(  0.0,  0.5, 0.5 );
  glVertex3f( -0.12,  0.5, 0.5 );
  glVertex3f( -0.12, -0.5, 0.5 );
  glEnd();

  // Dinding Belakang sisi tengah atas
  glBegin(GL_POLYGON);
  glColor3ub(5, 140, 250);
  glVertex3f(  0.3, 0.1, 0.5 );
  glVertex3f(  0.3,  0.5, 0.5 );
  glVertex3f( 0.0,  0.5, 0.5 );
  glVertex3f( 0.0, 0.1, 0.5 );
  glEnd();

  // Dinding Belakang sisi kanan
  glBegin(GL_POLYGON);
  glColor3ub(5, 140, 250);
  glVertex3f(  0.5, -0.5, 0.5 );
  glVertex3f(  0.5,  0.5, 0.5 );
  glVertex3f( 0.3,  0.5, 0.5 );
  glVertex3f( 0.3, -0.5, 0.5 );
  glEnd();

// JENDELA
  glBegin(GL_POLYGON);
  glColor3ub(5, 250, 83);
  glVertex3f(-0.3, 0.2 ,0.5);
  glVertex3f(-0.12, 0.2 ,0.5);
  glVertex3f(-0.12, -0.2 ,0.5);
  glVertex3f(-0.3, -0.2 ,0.5);
  glEnd();

  glBegin(GL_LINES);
  glLineWidth(.9);
  glColor3ub(61, 45, 2);
  glVertex3f(-0.3, 0.2 ,0.499);
  glVertex3f(-0.3, -0.2 ,0.499);
  glEnd();

  glBegin(GL_LINES);
  glLineWidth(0.9);
  glColor3ub(61, 45, 2);
  glVertex3f(-0.21, 0.2 ,0.499);
  glVertex3f(-0.21, -0.2 ,0.499);
  glEnd();

  glBegin(GL_LINES);
  glLineWidth(0.9);
  glColor3ub(61, 45, 2);
  glVertex3f(-0.12, 0.2 ,0.499);
  glVertex3f(-0.12, -0.2 ,0.499);
  glEnd();

  glBegin(GL_LINES);
  glLineWidth(0.9);
  glColor3ub(61, 45, 2);
  glVertex3f(-0.3, 0.2 ,0.499);
  glVertex3f(-0.12, 0.2 ,0.499);
  glEnd();

  glBegin(GL_LINES);
  glLineWidth(0.9);
  glColor3ub(61, 45, 2);
  glVertex3f(-0.3, 0.0 ,0.499);
  glVertex3f(-0.12, 0.0 ,0.499);
  glEnd();

  glBegin(GL_LINES);
  glLineWidth(0.9);
  glColor3ub(61, 45, 2);
  glVertex3f(-0.3, -0.2 ,0.499);
  glVertex3f(-0.12, -0.2 ,0.499);
  glEnd();
  
// END JENDELA

  bukapintu();

  glFlush();
  glutSwapBuffers();

}

//Animasi
void timer(int a){
  sudut+=1;
  glutPostRedisplay();
  if (sudut < 125){
    glutTimerFunc(10, timer, 0);
  }
}

void timerdua(int a){
  sudut-=1;
  glutPostRedisplay();
  if (sudut > 0){
    glutTimerFunc(10, timer, 0);
  }
}

//Control
void klik(int key, int state, int x, int y){
  if (key == GLUT_LEFT_BUTTON && state==GLUT_DOWN){
    buka += 1;
    printf("klik");
    glutTimerFunc(1, timer, 0);
  } 
  else if (key == GLUT_RIGHT_BUTTON && state==GLUT_DOWN){ 
    buka -= 1;
    printf("klok");
    glutTimerFunc(1, timerdua, 145);
  }
}
//Control
// void klok(unsigned char key, int state, int x, int y){
//   if (key == 'f' && state==GLUT_DOWN && buka==1){
//     buka -= 1;
//     printf("klok");
//     glutTimerFunc(1, timerdua, 0);
//   } 
// }


// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
void specialKeys( int key, int x, int y ) {

  //  Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;

  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;

  else if (key == GLUT_KEY_UP)
    rotate_x += 5;

  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;

  //  Request display update
  glutPostRedisplay();

}

void reshape(GLsizei width, GLsizei height)
{
    /*if(height == 0)
        height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0,0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();*/
    glScalef(0.4, 0.4, 0.4);
    //glu respectiv
}

// ----------------------------------------------------------
// main() function
// ----------------------------------------------------------
int main(int argc, char* argv[]){

  //  Initialize GLUT and process user parameters
  glutInit(&argc,argv);

  //  Request double buffered true color window with Z-buffer
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

  // Create window
  glutInitWindowSize(1000,1000);
  glutCreateWindow("Sweetroom");

  gluOrtho2D(-20.0, 20.0, -20.0, 20.0);

  //  Enable Z-buffer depth test
  glEnable(GL_DEPTH_TEST);

  // Callback functions
  glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);
  glutReshapeFunc(reshape);
  glutMouseFunc(klik);

  //  Pass control to GLUT for events
  glutMainLoop();

  //  Return to OS
  return 0;

}
