#include <GL/gl.h>
#include <GL/glut.h>
#include "Game.h"


#define COLUMNS 40
#define ROWS 40
#define FPS 10

void displayCallback();
void reshape_callback(int, int);
void timer_callback(int);

void Init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    initGrid(COLUMNS, ROWS);
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500,500);
    glutCreateWindow("SnakeGame Dos");
    glutDisplayFunc(displayCallback);
    glutReshapeFunc(reshape_callback);
    glutTimerFunc(0,timer_callback,0);
    Init();
    glutMainLoop();

    return 0;

}
int index = 0;
void displayCallback()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    glRectd(index,20,index + 2, 22);
    glRectd(20,index, 22, index + 2);
    index++;
    if(index > 40)
    {
        index = 0;
    }
    glutSwapBuffers();
}

void reshape_callback(int x, int y)
{
    glViewport(0,0,(GLsizei)x, (GLsizei)y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void timer_callback(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,timer_callback,0);
}