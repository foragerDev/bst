// bst.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "bst.h"
int main()
{   
    tree<int> number;
    number.insert(5);
    number.insert(4);
    number.insert(1);
    number.insert(-1);
    number.insert(3);
    number.insert(6);
    number.remove(5);
    number.get_minimum();
    std::cout << "Hello World!\n";
    std::cout << (number.get_minimum())->n_data << std::endl;
    std::cout << (number.get_maximum())->n_data << std::endl;
    std::cout << "After making a copy of the old tree." << std::endl;
    tree<int> another(number);
    another.insert(20);
    std::cout << (another.get_maximum())->n_data << std::endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
