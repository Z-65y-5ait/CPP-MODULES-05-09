#include "RPN.hpp"

RPN::RPN()
{
    std::cout << "Default Constructor Called" << std::endl;
}

RPN::~RPN()
{
    std::cout << "Destructor Called" << std::endl;
}

RPN& RPN::operator=(RPN& r)
{
    (void)r;
    return (*this);
}

RPN::RPN(RPN& r)
{
    (void)r;
}

int RPN::RpnWork(std::string str)
{
    std::stringstream space(str);
    std::string token;

    while (space >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            double n1;
            double n2;
            double res;

            if (this->my_stack.size() < 2)
                return (2);
            n1 = this->my_stack.top();
            this->my_stack.pop();
            n2 = this->my_stack.top();
            this->my_stack.pop();

            if (token == "+")
                res = n2 + n1;
            else if (token == "-")
                res = n2 - n1;
            else if (token == "*")
                res = n2 * n1;
            else
            {
                if (n1 != 0)
                    res = n2 / n1;
                else
                    return (2);
            }
            this->my_stack.push(res);
        }                    
        else
        {
            if (token.size() > 1 || !isdigit(token[0]))
                return (2);
            else
            {
                double n;

                n = token[0] - '0';
                this->my_stack.push(n);
            }
        }
    }
    if (this->my_stack.size() == 1)
        std::cout << this->my_stack.top() << std::endl;
    else
        return (2);
    return (1);
}