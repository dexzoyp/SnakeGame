#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPixmap>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QFrame>
#include <QTimer>

#include "snake.h"

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);
    ~Window();

    //Methods
    void keyPressEvent(QKeyEvent *keyEvent);
    int randomXY();
    void Eat();

    //Members
    Snake *snake;
    QLabel *testLabel;
    int blockSize=80;
private:
    QLabel *foodItem;
    QTimer *timer;
private slots:
    void Play();
};

#endif // WINDOW_H
