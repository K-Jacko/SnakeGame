#include <iostream>

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
void Setup()
{
    gameOver = false;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Draw()
{
    system("cls"); //Clears the View
    for (int i = 0; i < width; i++)
    std::cout << "#";
    std::cout << std::endl;

    for (int i = 0; i < height+2; ++i) {
        for (int j = 0; j < width; ++j) {
            if(j == 0)
            {
                std::cout << "#";
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


    for (int i = 0; i < width +2; i++)
        std::cout << "#";
    std::cout << std::endl;
}

void Input()
{

}

void Logic()
{

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
