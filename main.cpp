#include <GL/gl.h>
#include <GL/glut.h>

void displayCallback();

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500,500);
    glutCreateWindow("SnakeGame Dos");
    glutDisplayFunc(displayCallback);
    glutMainLoop();

    return 0;

}

void displayCallback()
{

    glutSwapBuffers();
}
