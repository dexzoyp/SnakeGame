#ifndef SNAKE_H
#define SNAKE_H
#include <iostream>
#include <vector>
#include <unistd.h>
#include <QPixmap>
#include <QLabel>
#include <QKeyEvent>
#include <QCoreApplication>


#define DEBUG

class Snake
{
public:
    Snake(QLabel *_snakeItem);
    void Move(int direction);
    void Grow(QLabel *si);
    bool GameOver();
    QPoint getPosition();
    std::vector<QLabel*>snake;
    std::vector<QLabel*>reserve;
    int lastDirection;
    QPoint lastPos;
    QPoint tempPos;
    int blockSize=80;


private:
    QLabel* snakeItem;

};

#endif // SNAKE_H
