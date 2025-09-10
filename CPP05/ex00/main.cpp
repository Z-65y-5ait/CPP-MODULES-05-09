#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat b1("Ahmed", 0);
        std::cout << b1 << std::endl;
        b1.IncrementGrade();
    } 
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Soufiane", 151);
        std::cout << b2 << std::endl;
        b2.IncrementGrade();
    } 
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Mouad", 75);
        std::cout << b3 << std::endl;
        b3.DecrementGrade();
    } 
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try{
        Bureaucrat b4("Aymane", 150);
        b4.DecrementGrade();
    }
    catch (const std::exception & e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
