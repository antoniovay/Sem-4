//
//  main.cpp
//  Lab 6 "Hash"
//
//  Created by Antony Miroshnichenko on 28.05.2024.
//

#include <iostream>
#include <assert.h>

//#include <QApplication>
//#include <QDebug>

//#include "MainWindow.hpp"

#include "HashTable.hpp"



//int main(int argc, char *argv[])
//{
//    QApplication app(argc, argv);
//    MainWindow mw;
//    mw.show();
//    return app.exec();
//}



int main() {
    HashTable t(6, new FirstHashFunction);
    t.add (33, "33");
    t.add (10, "10"); 
    t.add (44, "44");
    t.add (30, "30");
    t.add (50, "50");
    t.add (80, "80"); 
    std::cout << t;
    return 0;
}
