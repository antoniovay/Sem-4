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

//int main()
//{
//    HashTable table(5);
//
//    table.add(88, "one");
//    std::cout << table << std::endl;
//    table.add(72, "two");
//    table.add(22, "three");
//    table.add(59, "four");
//    table.add(61, "five");
//    table.add(22, "qwerty");
//    
//    std::cout << table << std::endl;
//    
//    table.remove(59);
//    
//    std::cout << table << std::endl;
//    
//    table.changeFunction(new SecondHashFunction);
//    
//    table.add(59, "desyat");
//    
//    std::cout << table << std::endl;
//    
//    return 0;
//}



//int main(int argc, char *argv[])
//{
//    QApplication app(argc, argv);
//    MainWindow mw;
//    mw.show();
//    return app.exec();
//}


int main() {
    HashTable t(7);
    SimpleHashFunction *hashFunction = new SimpleHashFunction;
    t.changeFunction (hashFunction);
    t.add (33, "33");
    t.add (10, "10"); 
    t.add (44, "44");
    t.add (30, "30");
    t.add (50, "50");
    t.add (80, "80"); 
    std::cout << t;
    return 0;
}
