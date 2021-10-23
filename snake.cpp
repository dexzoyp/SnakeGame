#include "snake.h"


Snake::Snake(QLabel* _snakeItem)
{
    snakeItem =_snakeItem;
    snake.push_back(snakeItem);
    snake.at(0)->move(160,160);
}
void Snake::Move(int direction)
{
#ifdef DEBUG
        std::cout<<"Move function reached"<<std::endl;
#endif
        lastPos.setX(snake.at(snake.size()-1)->x());
        lastPos.setY(snake.at(snake.size()-1)->y());

        int currentX=snake.at(0)->x();
        int currentY=snake.at(0)->y();

        for (unsigned long i = snake.size()-1; i > 0; --i)
        {
            snake.at(i)->move(snake.at(i-1)->pos());
        }
            switch (direction)
            {
            case 1: snake.at(0)->move(currentX+blockSize,currentY);
        #ifdef DEBUG
                std::cout<<"East"<<std::endl;
                std::cout<<"X: "<<currentX+blockSize<<" Y: "<<currentY<<std::endl;
        #endif
                break;
            case 2: snake.at(0)->move(currentX-blockSize,currentY);
        #ifdef DEBUG
                std::cout<<"West"<<std::endl;
                std::cout<<"X: "<<currentX-blockSize<<" Y: "<<currentY<<std::endl;
        #endif
                break;
            case 3: snake.at(0)->move(currentX,currentY-blockSize);
        #ifdef DEBUG
                std::cout<<"North"<<std::endl;
                std::cout<<"X: "<<currentX<<" Y: "<<currentY-blockSize<<std::endl;
        #endif
                break;
            case 4: snake.at(0)->move(currentX,currentY+blockSize);
        #ifdef DEBUG
                std::cout<<"South"<<std::endl;
                std::cout<<"X: "<<currentX<<" Y: "<<currentY+blockSize<<std::endl;
        #endif
                break;
            default:snake.at(0)->move(currentX,currentY);
            }
            tempPos = getPosition();
    #ifdef DEBUG
        std::cout<<std::endl;
    #endif
}
void Snake::Grow(QLabel* si)
{
    snake.push_back(si);
    reserve.pop_back();
    si->move(lastPos);
    si->show();
    std::cout<<"SNAKE SIZE: "<<snake.size()<<std::endl;
}
bool Snake::GameOver()
{
    if((0<=snakeItem->x() && snakeItem->x()<=560) && ( 0 <= snakeItem->y() && snakeItem->y() <= 560))
    {
        for (unsigned int i = 1; i < snake.size(); ++i)
        {
            if(snake.at(i)->pos() == snake.at(0)->pos())
            {
#ifdef DEBUG
        std::cout<<"GameOver!"<<std::endl;
#endif
                QCoreApplication::exit(0);
                return true;

            }
        }
#ifdef DEBUG
        std::cout<<"Running!"<<std::endl;
#endif
        return false;
    }
    else
    {
#ifdef DEBUG
        std::cout<<"GameOver!"<<std::endl;
#endif
        QCoreApplication::exit(0);
        return true;
    }
}
QPoint Snake::getPosition()
{
    return snakeItem->pos();
}
