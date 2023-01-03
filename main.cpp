#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include<iostream>

float xRotated = 90.0, yRotated = 0.0, zRotated = 0.0;

//------------------------------  reshapeFunc  ---------------------------------

void reshapeFunc (int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glFrustum(-1,1,-1,1,2,10);
    glLoadIdentity();
    gluPerspective (40.0, (GLdouble)w / (GLdouble)h, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

void Table()
{
    glTranslatef (0.0,-1,-15.0);
    gluLookAt(0,3,2,0,0,0,0,1,0);
   // glRotatef(40,0,1,0);
   // glRotatef(zRotated,0,1,0);

    glPushMatrix();
    glScalef(1.5,0.05,1);//for make the table
    glutSolidCube(6.0);
    glPopMatrix();
// inner part
    glPushMatrix();
    glTranslatef(0,0.5,-2.5);
    glRotatef(90,0,0,1);
    glScalef(0.05,1.5,0.05);//for make the table
    glutSolidCube(6.0);
    glPopMatrix();
// front part
     glPushMatrix();
    glTranslatef(0,0.5,3);
    glRotatef(90,0,0,1);
    glScalef(0.05,1.5,0.05);//for make the table
    glutSolidCube(6.0);
    glPopMatrix();
//right player
    glPushMatrix();
    glTranslatef(4.5,0.5,0);
    glRotatef(90,1,0,0);
    glScalef(0.2,1,0.2);//for make the table
    glutSolidCube(1.0);
    glPopMatrix();
     //left player
    glPushMatrix();
    glTranslatef(-4.5,0.5,0);
    glRotatef(90,1,0,0);
    glScalef(0.2,1,0.2);//for make the table
    glutSolidCube(1.0);
    glPopMatrix();
//boll
    glPushMatrix();
    glutSolidSphere (0.3, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,7,0);
   glutSolidSphere (0.5, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5,7,0);
   glutSolidSphere (0.5, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1,7,0);
   glutSolidSphere (0.5, 30, 30);
    glPopMatrix();
    glutPostRedisplay();

}
////------------------------------  display   -------------------------------
void display (void)
{
     GLfloat Pos[]= {0,1,0,1};
    GLfloat Col[]= {1,0,0,1};
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity ();
    glLightfv(GL_LIGHT0,GL_POSITION,Pos);
   glLightfv(GL_LIGHT0,GL_POSITION,Col);
       Table();

    glutSwapBuffers();
}

//--------------------------------  idleFunc  ----------------------------------

//void idleFunc (void)
//{
//    zRotated += 0.01;
//    glutPostRedisplay();
//}

void texture (void)
{

    const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
    const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

    const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
    const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
    const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


}



//----------------------------------  main  ------------------------------------


int main (int argc, char **argv)
{
    glutInit               (&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // buffer mode
    glutInitWindowSize     (800, 800);
    glutInitWindowPosition (700, 200);
    glutCreateWindow       ("20100067/20109328");
// gluPerspective(90,2.5,0.5,20);
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glRotatef(1,1,0,0);
    glutDisplayFunc (display);
    glutReshapeFunc (reshapeFunc);
//    glutIdleFunc    (idleFunc);
   glClearColor(0,1,1,1); //COLOR FOR THE PACKGROUND
    texture(); // Lighting and textures


    glutMainLoop();
}

