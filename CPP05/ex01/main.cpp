#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat high("Ahmed", 1);
        Bureaucrat mid("Aymane", 75);
        Bureaucrat low("Fatima", 150);

        Form taxForm("Tax Form", 50, 75);
        Form secretForm("Birth Form", 1, 1);

        std::cout << taxForm << std::endl;
        std::cout << secretForm << std::endl;

        high.signForm(taxForm);
        high.signForm(secretForm);

        mid.signForm(taxForm);

        low.signForm(secretForm);

        std::cout << taxForm << std::endl;
        std::cout << secretForm << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception Unhandled: " << e.what() << std::endl;
    }

    return 0;
}
