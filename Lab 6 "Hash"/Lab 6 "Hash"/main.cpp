//
//  main.cpp
//  Lab 6 "Hash"
//
//  Created by Antony Miroshnichenko on 28.05.2024.
//

#include <iostream>
#include <assert.h>

#include <QApplication>
#include <QDebug>

#include "MainWindow.hpp"

#include "HashTable.hpp"

int main()
{
    HashTable table(5);

    table.add(88, "one");
    //std::cout << table << std::endl;
    table.add(72, "two");
    table.add(22, "three");
    table.add(59, "four");
    table.add(61, "five");
    //table.add(22, "qwerty");
    
    std::cout << table << std::endl;
    
    table.remove(59);
    
    std::cout << table << std::endl;
    
    //table.changeFunction(new SecondHashFunction);
    
    table.add(59, "desyat");
    
    std::cout << table << std::endl;
    
    return 0;
}



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mw;
    mw.show();
    return app.exec();
}
