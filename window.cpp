#include "window.h"

Window::Window(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(640,640);
    srand(time(0));
    //Image resources
    QPixmap snakePic("img/snake.png");
    QPixmap playground("img/playground.png");
    QPixmap food("img/food.png");


    //Creating the background ( white )
    QLabel *bg = new QLabel(this);
    bg->setPixmap(playground);

    //Creating the food
    foodItem = new QLabel(this);
    foodItem->setPixmap(food);
    foodItem->move(randomXY(),randomXY());
    foodItem->pos();

    //Creating the Snake
    QLabel *snakeItem = new QLabel(this);
    snakeItem->setPixmap(snakePic);
    snake = new Snake(snakeItem);

    for (int i = 0; i < 64; ++i)
    {
        QLabel* item = new QLabel(this);
        item->setPixmap(snakePic);
        snake->reserve.push_back(item);
        item->hide();
    }

    QLabel* si= new QLabel(this);
    si->setPixmap(snakePic);
    snake->Grow(si);

    //Using timer
    timer = new QTimer;
    timer->setInterval(200);
    connect(timer,SIGNAL(timeout()),this,SLOT(Play()));
}

void Window::keyPressEvent(QKeyEvent *keyEvent)
{

    switch (keyEvent->key())
    {
    case Qt::Key_Down:
        if(snake->lastDirection !=3 && snake->lastDirection !=4)
        {
        snake->Move(4);
        snake->lastDirection = 4;
        timer->start();
        }
        break;
    case Qt::Key_Left:
        if(snake->lastDirection !=1 && snake->lastDirection !=2)
        {
        snake->Move(2);
        snake->lastDirection = 2;
        timer->start();
        }
        break;
    case Qt::Key_Right:
        if(snake->lastDirection !=2 && snake->lastDirection !=1)
        {
        snake->Move(1);
        snake->lastDirection = 1;
        timer->start();
        }
        break;
    case Qt::Key_Up:
        if(snake->lastDirection !=4 && snake->lastDirection !=3)
        {
        snake->Move(3);
        snake->lastDirection = 3;
        timer->start();
        }
        break;
    default: snake->Move(1);
        break;
    }
}

int Window::randomXY()
{
    int temp = rand()%8;
    return temp*blockSize;
}

void Window::Play()
{
    if(!snake->GameOver())
    {
        if(snake->tempPos != foodItem->pos())
        {
        snake->Move(snake->lastDirection);
        }
        else
        {
        std::cout<<"Eat"<<std::endl;
        Eat();
        }
    }
}
void Window::Eat()
{
    QLabel* si;
    si = snake->reserve.back();
    snake->Grow(si);

    foodItem->move(randomXY(),randomXY());
    foodItem->hide();

    for (unsigned int i = 0; i < snake->snake.size(); ++i)
    {
        if(snake->snake.at(i)->pos() == foodItem->pos())
        {
            foodItem->move(randomXY(),randomXY());
        }
    }
    foodItem->show();
}
Window::~Window()
{

}
