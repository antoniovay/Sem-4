//
//  main.cpp
//  Lab 3 "Search Tree"
//
//  Created by Antony Miroshnichenko on 15.04.2024.
//

#include <iostream>
#include "SearchTree.hpp"

int main()
{
    
    SearchTree tree;
    
    tree.add(10);
    tree.add(20);
    tree.add(5);
    tree.add(6);
    tree.add(50);
    tree.add(1);
    tree.add(9);
    tree.add(17);
    tree.add(70);
    tree.add(0);

    
    tree.printVertical();
    
    tree.remove(10);
    
    tree.printVertical();
    
}
