//
//  main.cpp
//  HashTableVector
//
//  Created by Antony Miroshnichenko on 28.06.2024.
//

#include <iostream>

#include <QApplication>
#include <QDebug>

#include "MainWindow.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mw;
    mw.show();
    return app.exec();
}
