#include "RPN.hpp"

int main(int argc, char **argv)
{
    RPN r;
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << "argument" << std::endl;
        return (2);
    }
    if (r.RpnWork(argv[1]) == 2)
        return (std::cerr << "Error" << std::endl, 2);
}