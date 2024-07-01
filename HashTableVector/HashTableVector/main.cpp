//
//  main.cpp
//  HashTableVector
//
//  Created by Antony Miroshnichenko on 28.06.2024.
//

#include <iostream>

#include "HashTable.hpp"

//#include <QApplication>
//#include <QDebug>

//#include "MainWindow.hpp"

//int main(int argc, char *argv[])
//{
//    QApplication app(argc, argv);
//    MainWindow mw;
//    mw.show();
//    return app.exec();
//}

int main() {
    
    FirstHashFunction first;
    HashTable<std::string> table(10, &first);
    
    table.print();
    std::cout << std::endl;
    
    table.add(1, "one");
    table.add(43, "two");
    table.add(15, "three");
    table.add(16, "four");
    table.add(58, "five");
    table.add(77, "six");
    table.add(85, "seven");
    table.add(6, "eight");
    table.add(11, "nine");
    table.add(14, "ten");
    table.add(1000000, "eleven");
    table.add(100, "twelve");
    
    table.print();
    
    return 0;
}
