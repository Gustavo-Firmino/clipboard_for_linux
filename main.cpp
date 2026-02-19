#include <QApplication>
#include "CopyCATWindow.h"
#include <iostream>
#include <thread>

void ThreadShowInterface() {

}

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    CopyCATWindow window;
    window.show();

    return a.exec();
}