#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>

class RPN
{
    private:
        std::stack<double> my_stack;
    public:
        RPN();
        ~RPN();
        RPN& operator=(RPN& r);
        RPN(RPN& r);
        int RpnWork(std::string str);
};

#endif