#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

class BitcoinExchange
{
    private:
        std::map<std::string, float> my_map;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange& b);
        BitcoinExchange(const BitcoinExchange& b);
        void PutDataBase();
        void CheckInputFile(std::string file_name);
        int CheckDate(std::string date);
        int CheckValue(std::string value_str);
        std::string TrimInput(std::string str);
        float MainWork(std::string date, std::string value_str);
};

#endif