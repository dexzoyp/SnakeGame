#include "window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    system("pwd");
    Window w;
    w.show();

    return a.exec();
}
