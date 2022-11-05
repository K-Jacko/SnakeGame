//
// Created by Wake on 05/11/2022.
//
#include <GL/gl.h>
#include <GL/glut.h>
#include "Game.h"

int gridX, gridY;
void unit(int x, int y);

void initGrid(int x, int y)
{
    gridX = x;
    gridY = y;
}

void drawGrid()
{
    for (int x=0; x < gridX; x++)
    {
        for (int y=0; y < gridY; y++)
        {
            unit(x,y);
        }
    }
}

void unit(int x, int y)
{
    if(x == 0  || y == 0 || x == gridX - 1 || y == gridY -1)
    {
        glLineWidth(3.0);
        glColor3f(1.0,1.0,1.0);
    }
    else
    {
        glLineWidth(1.0);
        glColor3f(1.0,1.0,1.0);
    }

    //Begin draw
    glBegin(GL_LINE_LOOP);
        glVertex2f(x,y);
        glVertex2f(x+1,y);
        glVertex2f(x+1,y+1);
        glVertex2f(x,y+1);
    //End draw
    glEnd();
}