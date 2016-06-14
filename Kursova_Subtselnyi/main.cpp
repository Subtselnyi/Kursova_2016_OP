#include <QApplication>
#include "graph.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   Graph *wnd = new Graph();
   wnd->show();//виклик діалогового вікна


    return a.exec();
}
