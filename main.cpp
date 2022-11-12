#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include "Game.h"


#define COLUMNS 40
#define ROWS 40
#define FPS 10

bool gameOver = false;
int score = 0;
void displayCallback();
void reshape_callback(int, int);
void timer_callback(int);
void keyboard_callback(int, int, int);

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
    glutSpecialFunc(keyboard_callback);
    Init();
    glutMainLoop();

    return 0;

}

void displayCallback()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    drawSnake();
    drawFood();
    glutSwapBuffers();
    if(gameOver)
    {
        char _score[10];
        itoa(score,_score,10);
        char text[50] = "Your Score : ";
        strcat(text,_score);
        MessageBox(NULL, text, "GAME OVER", 0);
        exit(0);
    }
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

void keyboard_callback(int key,int,int)
{
    switch (key) {
        case GLUT_KEY_UP:
            if(sDirection != DOWN)
                sDirection = UP;
            break;
        case GLUT_KEY_DOWN:
            if(sDirection != UP)
                sDirection = DOWN;
            break;
        case GLUT_KEY_RIGHT:
            if(sDirection != LEFT)
                sDirection = RIGHT;
            break;
        case GLUT_KEY_LEFT:
            if(sDirection != RIGHT)
                sDirection = LEFT;
            break;
    }
}