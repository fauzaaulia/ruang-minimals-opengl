#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
 //memberikan fileheader yang dibutuhkan
GLuint texture[35];

GLint slices = 35;
GLint stacks = 35;

using namespace std;
static float ypos = 0, zpos = 0, xpos = 0,a = -9, b = -5,c =-30, laptop=0, laci=0, kursi=0, pintu=0;
int z=0;

struct Image {
  unsigned long sizeX;
  unsigned long sizeY;
  char *data;
};
typedef struct Image Image; //struktur data untuk
//ukuran image #bisa di set sesuai kebutuhan
#define checkImageWidth 164
#define checkImageHeight 164

GLubyte checkImage[checkImageWidth][checkImageHeight][3];

//mengambil tekstur
void init(void)
{
  glClearColor(0.5, 0.5, 0.5, 0.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    // Generate texture/ membuat texture background
}

//fungsi kotak kosong, belum diisi koordinat. diisi di display()
void kotak(float x1,float y1,float z1,float x2,float y2,float z2)
{
  //depan
  glTexCoord2f(0.0, 0.0);
  glVertex3f(x1,y1,z1);
  glTexCoord2f(0.0, 1.0);
  glVertex3f(x2,y1,z1);
  glTexCoord2f(1.0, 1.0);
  glVertex3f(x2,y2,z1);
  glTexCoord2f(1.0, 0.0);
  glVertex3f(x1,y2,z1);
  //atas
  glTexCoord2f(0.0, 0.0);
  glVertex3f(x1,y2,z1);
  glTexCoord2f(0.0, 1.0);
  glVertex3f(x2,y2,z1);
  glTexCoord2f(1.0, 1.0);
  glVertex3f(x2,y2,z2);
  glTexCoord2f(1.0, 0.0);
  glVertex3f(x1,y2,z2);
  //belakang
  glTexCoord2f(0.0, 0.0);
  glVertex3f(x1,y2,z2);
  glTexCoord2f(0.0, 1.0);
  glVertex3f(x2,y2,z2);
  glTexCoord2f(1.0, 1.0);
  glVertex3f(x2,y1,z2);
  glTexCoord2f(1.0, 0.0);
  glVertex3f(x1,y1,z2);
  //bawah
  glTexCoord2f(0.0, 0.0);
  glVertex3f(x1,y1,z2);
  glTexCoord2f(1.0, 0.0);
  glVertex3f(x2,y1,z2);
  glTexCoord2f(1.0, 1.0);
  glVertex3f(x2,y1,z1);
  glTexCoord2f(0.0, 1.0);
  glVertex3f(x1,y1,z1);
  //samping kiri
  glTexCoord2f(0.0, 0.0);
  glVertex3f(x1,y1,z1);
  glTexCoord2f(1.0, 0.0);
  glVertex3f(x1,y2,z1);
  glTexCoord2f(1.0, 1.0);
  glVertex3f(x1,y2,z2);
  glTexCoord2f(0.0, 1.0);
  glVertex3f(x1,y1,z2);
  //samping kanan
  glTexCoord2f(0.0, 0.0);
  glVertex3f(x2,y1,z1);
  glTexCoord2f(1.0, 0.0);
  glVertex3f(x2,y2,z1);
  glTexCoord2f(1.0, 1.0);
  glVertex3f(x2,y2,z2);
  glTexCoord2f(0.0, 1.0);
  glVertex3f(x2,y1,z2);
}

//Controler
void keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
    //putar arah jarum jam (menambah derajat putaran)
    case 'q':
    ypos=ypos+5;
    if (ypos>360) ypos=0;
    glutPostRedisplay();
    break;
    //putar berlawanan arah jarum jam (mengurangi derajat putaran)
    case 'e':
    ypos=ypos-5;
    if (ypos>360) ypos=0;
    glutPostRedisplay();
    break;
    //vertikal bawah (menambah koordinat y)
    case 'f':
    b = b + 1;
    glutPostRedisplay();
    break;
    //vertikal atas (mengurangi koordinat y)
    case 'r':
    b = b - 1;
    glutPostRedisplay();
    break;
    //horisontal kiri (mengurangi koordinat x)
    case 'a':
    a = a + 1;
    glutPostRedisplay();
    break;
    //horisontal kanan (menambah koordinat x)
    case 'd':
    a = a - 1;
    glutPostRedisplay();
    break;
    //memperbesar objek (menambah koordinat z)
    case 'w':
    c = c + 1;
    glutPostRedisplay();
    break;
    //memperkecil abjek(mengurangi koordinat z)
    case 's':
    c = c - 1;
    glutPostRedisplay();
    break;

    //buka pintu
    case 'p':
    pintu=pintu-5;
    if (pintu<-45) pintu=-45;
    glutPostRedisplay();
    break;
    //tutup pintu
    case 'o':
    pintu=pintu+5;
    if (pintu>0) pintu=0;
    glutPostRedisplay();
    break;
    
    //buka laptop
    case 'l':
    laptop=laptop-5;
    if (laptop<-60) laptop=-60;
    glutPostRedisplay();
    break;
    //tutup laptop
    case 'k':
    laptop=laptop+5;
    if (laptop>90) laptop=90;
    glutPostRedisplay();
    break;
    
    //buka laci
    case '.':
    laci=laci+0.1;
    if (laci>2) laci=2;
    glutPostRedisplay();
    break;
    //tutup laci
    case ',':
    laci=laci-0.1;
    if (laci<0) laci=0;
    glutPostRedisplay();
    break;
    
    //buka kursi
    case 'm':
    kursi=kursi+0.1;
    if (kursi>2.5) kursi=2.5;
    glutPostRedisplay();
    break;
    //tutup kursi
    case 'n':
    kursi=kursi-0.1;
    if (kursi<-4) kursi=-4;
    glutPostRedisplay();
    break;

    //putar arah jarum jam (menambah derajat putaran)
    case 'z':
    xpos=xpos+5;
    if (xpos>360) xpos=0;
    glutPostRedisplay();
    break;
    //putar berlawanan arah jarum jam (mengurangi derajat putaran)
    case 'c':
    xpos=xpos-5;
    if (xpos>360) xpos=0;
    glutPostRedisplay();
  }
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity ();
  glEnable(GL_DEPTH_TEST);
  //perpindahan
  glTranslatef(a,b,c);
  //putaran
  glRotatef(xpos,1,0,0);
  glRotatef(ypos,0,1,0);
  glRotatef(zpos,0,0,1);

  //lantai
  glPushMatrix();
    glBegin(GL_QUADS);
      glColor3f(0.3f,0.3f,0.3f);
      kotak(0,0,18,25,0.5,0);
    glEnd();
  glPopMatrix();
  //dinding kiri
  glPushMatrix();
    glBegin(GL_QUADS);
      glColor3ub(255, 125, 185);
      kotak(0,0.5,18,0.5,10,0);
    glEnd();
  glPopMatrix();
  //dinding belakang
  glPushMatrix();
    glBegin(GL_QUADS);
      glColor3ub(5, 140, 250);
      kotak(6,0.5,0.5,25,10,0.0);
    glEnd();
  glPopMatrix();

  //meja
    //atas
    glPushMatrix();
      glBegin(GL_QUADS);
          glColor3ub(255, 234, 166);
            kotak(21,3.5,16,24.8,3.8,9.5);
      //kaki kanan belakang
            kotak(24.3,0.5,15.9,24.6,3.6,15.6);
      //kaki kiri belakang 
            kotak(24.3,0.5,9.9,24.6,3.6,9.6);
      //kaki kiri depan
            kotak(21.1,0.5,9.9,21.4,3.6,9.6);
      //kaki kanan depan 
            kotak(21.1,0.5,15.9,21.4,3.6,15.6);
      glEnd();
    glPopMatrix();

  //pc
    glPushMatrix();
      glBegin(GL_QUADS);
        glColor3f(0.0f,0.0f,0.0f);
        //keyboard
        kotak(23.3,3.8,15.0,22,4,13.0);
      glEnd();
    glPopMatrix();
    //Monitor lcd
      glPushMatrix();
        glTranslatef(23.3,3.8,13.0);
        glRotatef(laptop, 0.0, 0.0, 0.1);
          glBegin(GL_QUADS);
              glColor3f(0.0f,0.0f,0.0f);
              //Monitor lcd
              kotak(0,0,0,0.1,1.5,2.0);
          glEnd();
      glPopMatrix();
    //layar lcd
      glPushMatrix();
        glTranslatef(23.29,3.8,13.0);
        glRotatef(laptop, 0.0, 0.0, 0.1);
          glBegin(GL_QUADS);
            glColor3f(1.1f,1.0f,1.0f);
            kotak(0,0.1,0.1,0.01,1.4,1.9);
          glEnd();
      glPopMatrix();

  //kursi
    //alas
      glPushMatrix();
        glTranslatef(kursi,0,0);
          glBegin(GL_QUADS);
              glColor3f(0.2f,0.1f,0.1f);
              kotak(18,2.2,15.5,20.8,2.5,12.8);
          //kiri depan
              kotak(20.5,0.5,15.5,20.8,2.5,15.2);
          //kanan depan
              kotak(20.5,0.5,13.1,20.8,2.5,12.8);
          //kanan belakang
              kotak(18,0.5,13.1,18.3,5.2,12.8);
          //kiri belakang
              kotak(18,0.5,15.5,18.3,5.2,15.2);
          //senderan
              kotak(18,3.8,15.5,18.2,4.9,12.8);
          glEnd();
      glPopMatrix();

  //kasur
    //rangka alas
      glPushMatrix();
        glBegin(GL_QUADS);
          glColor3f(0.6f,0.1f,0.1f);
            kotak(1.1,1.4,15.5,13.4,3,8.7);
        //kaki 1
            kotak(0.5,0.5,15.6,1.2,6,14.9);
        //kaki 2
            kotak(0.5,0.5,9.4,1.1,6,8.7);
        //kaki 3
            kotak(12.9,0.5,9.4,13.6,5,8.7);
        //kaki 4
            kotak(12.9,0.5,15.6,13.6,5,14.9);
        //penyangga depan
            kotak(0.6,3,15.4,1,5.1,8.9);
        //penyangga belakang
            kotak(12.9,1.4,15.4,13.6,4.5,8.9);
        glEnd();
      glPopMatrix();
    //kasurnya
    glPushMatrix();
      glBegin(GL_QUADS);
          glColor3f(1.1f,1.1f,1.1f);
            kotak(1.1,2.5,15.4,13.4,3.5,9);
          //bantal
          glColor3f(0.6f,0.6f,0.6f);
            kotak(1.3,3.5,14.4,4,4,10);
          //selimut
          glColor3f(0.1f,1.1f,0.1f);
            kotak(5,3.5,15.4,13.4,3.7,9);
          //kanan
            kotak(5,3,9,13.4,3.6,8.9);
          //kiri
            kotak(5,3,15.5,13.4,3.6,15.4);
      glEnd();
    glPopMatrix();

  //Pintu
    glPushMatrix();
      glRotatef(pintu, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);
          glColor3f(0.1f,0.0f,0.0f);
          kotak(0.5,0.5,0.5,6,10,0);
        glEnd();
    glPopMatrix();
    //gagang pintu
      glPushMatrix();
        glRotatef(pintu, 0.0, 1.0, 0.0);
          glBegin(GL_QUADS);
            //gagang pintu
            glColor3f(1.0f,1.0f,1.0f);
              kotak(5.2,5.8,0.7,5.5,6,0.5);
              kotak(4.5,5.8,0.9,5.6,6,0.7);
            //alas gagang
              kotak(5.1,6.5,0.55,5.7,5,0.5);
            glColor3f(0.0f,0.0f,0.0f);
              kotak(5.35,5.2,0.56,5.45,5.5,0.55);
          glEnd();
      glPopMatrix();
    //gagang pintu belakang
      glPushMatrix();
        glRotatef(pintu, 0.0, 1.0, 0.0);
          glBegin(GL_QUADS);
            //gagang pintu
            glColor3f(1.0f,1.0f,1.0f);
              kotak(5.2,5.8,0,5.5,6,-0.2);
              kotak(4.5,5.8,-0.2,5.6,6,-0.4);
            //alas gagang
              kotak(5.1,6.5,0,5.7,5,-0.05);
            glColor3f(0.0f,0.0f,0.0f);
              kotak(5.35,5.2,-0.05,5.45,5.5,-0.06);
          glEnd();
      glPopMatrix();

  //saklar
    glPushMatrix();
      glBegin(GL_QUADS);
        glColor3f(1.1f,1.0f,1.0f);
          kotak(6.5,6.5,0.6,7.5,7.5,0.5);
        glColor3f(0.1f,0.0f,0.0f);
          kotak(6.65,6.7,0.65,6.92,7.3,0.6);
          kotak(7.08,6.7,0.65,7.35,7.3,0.6);
      glEnd();
    glPopMatrix();

  //lukisan atas kasur
    glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, texture[9]);
        glBegin(GL_QUADS);
          glColor3f(1.0f,1.0f,1.0f);
            kotak(0.6,6.6,15.5,0.61,8.8,8.9);
          glColor3f(0.0f,0.0f,0.0f);
            kotak(0.5,6.4,15.7,0.6,9,8.7);
        glEnd();
    glPopMatrix();

  //lemari kecil
    glPushMatrix();
      glBegin(GL_QUADS);
          glColor3ub(209, 129, 67);
            kotak(0.5,0.8,8.5,4,4.5,4.7);
            //kaki kiri
            kotak(0.5,0.5,8.5,4.3,4.9,8.3);
            //kaki kanan
            kotak(0.5,0.5,4.5,4.3,4.9,4.7);
      glEnd();
    glPopMatrix();
    //pegangan
      glPushMatrix();
        glTranslatef(laci,0,0);
        glBegin(GL_QUADS);
          glColor3ub(209, 129, 67);
            kotak(4.2,2.1,6.9,4.3,2.3,6.2);
            kotak(4.2,3.9,6.9,4.3,4.1,6.2);
        glEnd();
      glPopMatrix();            
    //lacinya
      glPushMatrix();
        glTranslatef(laci,0,0);
        glBegin(GL_QUADS);
          glColor3f(0.3f,0.1f,0.1f);
            kotak(1.9,1.0,8.2,4.2,2.5,4.9);
            kotak(1.9,2.7,8.2,4.2,4.3,4.9);
        glEnd();
      glPopMatrix();

  //Rak Dinding
    glPushMatrix();
      glBegin(GL_QUADS);
        glColor3ub(255, 8, 70);
          //bawah
          kotak(10,6,1.5,18,6.2,0.5);
          //atas
          kotak(10,7,1.5,18,7.2,0.5);
        glColor3ub(82, 8, 255);
          //kanan
          kotak(15.0,5.0,1.5,15.2,8.5,0.5);
          //kiri
          kotak(13,5.0,1.5,13.2,8.5,0.5);
      glEnd();
    glPopMatrix();

  glFlush();
  glutSwapBuffers();
}

void reshape (int w, int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, 1.0 * (GLfloat) w / (GLfloat) h, 1.0, 40.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0, 0.0, 0.0);
  gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize (1024, 600);
  glutInitWindowPosition (20, 75);
  glutCreateWindow ("Interior");
  cout<<"\nTugas OpenGL - Interior Rumah"<<endl;
  cout<<"================================"<<endl<<endl;
  cout<<"kelompok 5"<<endl;
  init ();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
