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

//int main()
//{
//    HashTable table(5);
//
//    assert(table.add(88, "raz"));
//    //std::cout << table << std::endl;
//    table.add(72, "dva");
//    table.add(22, "tri");
//    table.add(59, "chetyire");
//    table.add(61, "pyat");
//    //table.add(22, "qwerty");
//    
//    std::cout << table << std::endl;
//    
//    table.remove(59);
//    
//    std::cout << table << std::endl;
//    
//    //table.changeFunction(new SecondHashFunction);
//    
//    table.add(59, "desyat");
//    
//    std::cout << table << std::endl;
//    
//    return 0;
//}



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mw;
    mw.show();
    return app.exec();
}
