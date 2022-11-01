#include <iostream>
#include <conio.h>
#include <random>
#include <windows.h>
//In making a game you should separate the program into these parts
// 1) Setup
// 2) Draw
// 3) Input
// 4) Logic
bool gameOver;
bool isReplay;
const int width = 40;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection {Stop = 0, Left, Right, Up, Down};
eDirection dir;
int tailX[100], tailY[100];
int nTail;
void PlaceFruit();
void DrawBanner();
void Setup()
{
    for (int i = 0; i < nTail; ++i) {
        std::fill_n(tailX, i, 0);
        std::fill_n(tailY, i, 0);
    }
    nTail = 0;
    isReplay = false;
    gameOver = false;
    dir = Stop;
    x = width / 2;
    y = height / 2;
    PlaceFruit();
    score = 0;
}

void Draw()
{
    system("cls");//Clears the View
    DrawBanner();
    for (int i = 0; i < width; i++)
    std::cout << "#";
    std::cout << std::endl;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width + 2; ++j) {
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
                bool print = false;
                for (int k = 0; k < nTail; ++k)
                {

                    if(tailX[k] == j && tailY[k] == i)
                    {
                        std::cout << "o";
                        print = true;
                    }
                }
                if(!print)
                    std::cout << " ";
            }
            if (j == width -1)
            {
                std::cout << "#";
            }
        }
        std::cout << std::endl;
    }


    for (int i = 0; i < width + 2; i++)
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
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; ++i)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

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

    if(x >= width) x = 0; else if(x < 0) x = width - 1;
    if(y >= height) y = 0; else if(y < 0) y = height - 1;

    for (int i = 0; i < nTail; ++i)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            gameOver = true;
        }
    }
    if(y == fruitX && x == fruitY)
    {
        score += 10;
        PlaceFruit();
        nTail++;
    }
}

void ReplayLogic()
{
    system("pause");

    switch (_getch()) {
        case 'y' :
            gameOver = false;
            isReplay = true;
            break;
        case 'n' :
            gameOver = true;
            isReplay = true;
            break;
        }

}

void PlaceFruit()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distW(0, width / 2);
    std::uniform_int_distribution<int> distL(0, height / 2);
    fruitX = distW(mt);
    fruitY = distL(mt);
}

void DrawBanner()
{

    std::cout << "\n\n" << std::endl;
    std::cout<<"# ____  __.              ____.              __       /\\          _________              __              ________                       #"<<std::endl;
    std::cout<<"#|    |/ _|             |    |____    ____ |  | _____)/ ______  /   _____/ ____ _____  |  | __ ____    /  _____/_____    _____   ____  #"<<std::endl;
    std::cout<<"#|      <    ______     |    \\__  \\ _/ ___\\|  |/ /  _ \\/  ___/  \\_____  \\ /    \\\\__  \\ |  |/ // __ \\  /   \\  ___\\__  \\  /     \\_/ __ \\ #"<<std::endl;
    std::cout<<"#|    |  \\  /_____/ /\\__|    |/ __ \\\\  \\___|    <  <_> )___ \\   /        \\   |  \\/ __ \\|    <\\  ___/  \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/ #"<<std::endl;
    std::cout<<"#|____|__ \\         \\________(____  /\\___  >__|_ \\____/____  > /_______  /___|  (____  /__|_ \\\\___  >  \\______  (____  /__|_|  /\\___  >#"<<std::endl;
    std::cout<<"#        \\/                       \\/     \\/     \\/         \\/          \\/     \\/     \\/     \\/    \\/          \\/     \\/      \\/     \\/ #"<<std::endl;
}

void DrawDeathBanner()
{
    std::cout << "\n\n" << std::endl;
    std::cout<<"#  ________                        ________                                __________              .__                _________  _____.___.     /\\         #"<<std::endl;
    std::cout<<"# /  _____/_____    _____   ____   \\_____  \\___  __ ___________            \\______   \\ ____ ______ |  | _____  ___.__.\\_____   \\ \\__  |   |    / /   ____  "<<std::endl;
    std::cout<<"#/   \\  ___\\__  \\  /     \\_/ __ \\   /   |   \\  \\/ // __ \\_  __ \\   ______   |       _// __ \\\\____ \\|  | \\__  \\<   |  |   /   __/  /   |   |   / /   /    \\ #"<<std::endl;
    std::cout<<"#\\    \\_\\  \\/ __ \\|  Y Y  \\  ___/  /    |    \\   /\\  ___/|  | \\/  /_____/   |    |   \\  ___/|  |_> >  |__/ __ \\\\___  |  |   |     \\____   |  / /   |   |  \\#"<<std::endl;
    std::cout<<"# \\______  (____  /__|_|  /\\___  > \\_______  /\\_/  \\___  >__|               |____|_  /\\___  >   __/|____(____  / ____|  |___|     / ______| / /    |___|  /#"<<std::endl;
    std::cout<<"#        \\/     \\/      \\/     \\/          \\/          \\/                          \\/     \\/|__|             \\/\\/       <___>     \\/        \\/          \\/ #"<<std::endl;
}

int main() {


    n:
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(10);
    }
    while (!isReplay)
    {
        DrawDeathBanner();
        ReplayLogic();
        if(!gameOver)
        {
            goto n;
        }

    }
    return 0;

}
