#include <iostream>
#include <conio.h>
#include <random>
//In making a game you should separate the program into these parts
// 1) Setup
// 2) Draw
// 3) Input
// 4) Logic
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection {Stop = 0, Left, Right, Up, Down};
eDirection dir;
void PlaceFruit();
void Setup()
{
    gameOver = false;
    dir = Stop;
    x = width / 2;
    y = height / 2;
    PlaceFruit();
    score = 0;
}

void Draw()
{
    system("cls"); //Clears the View
    for (int i = 0; i < width; i++)
    std::cout << "#";
    std::cout << std::endl;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width ; ++j) {
            if(j == 0)
            {
                std::cout << "#";
            }
            if(i == y && j == x)
            {
                std::cout << "O";
            }
            else if(i == fruitX && j == fruitY)
            {
                std::cout << "F";
            }
            else
            {
                std::cout << " ";
            }
            if (j == width -1)
            {
                std::cout << "#";
            }
        }
        std::cout << std::endl;
    }


    for (int i = 0; i < width ; i++)
        std::cout << "#";
    std::cout << std::endl;
    std::cout << "Score:" << score << std::endl;
}

void Input()
{
    if(_kbhit())
    {
        switch (_getch()) {

            case 'a':
                dir = Left;
                break;

            case 'w':
                dir = Up;
                break;
            case 's':
                dir = Down;
                break;
            case 'd':
                dir = Right;
                break;
            case 'x' :
                gameOver = true;
                break;
        }
    }
}

void Logic()
{
    switch (dir) {
        case Left :
            x--;
            break;
        case Right :
            x++;
            break;
        case Up :
            y--;
            break;
        case Down :
            y++;
            break;
        default:
            break;
    }

    if(x > width || x < 0 || y > height || y < 0)
    {
        gameOver = true;
    }

    if(x == fruitX && y == fruitY)
    {
        score += 10;
        PlaceFruit();
    }
}

void PlaceFruit()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distW(0, width);
    std::uniform_int_distribution<int> distL(0, height);
    fruitX = distW(mt);
    fruitY = distL(mt);
}

int main() {
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
    }
    return 0;
}
