#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << "Default Constructor Called" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "Destructor Called" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& b)
{
    // b.my_map = this->my_map;
    return (*this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& b)
{
    (void)b;
}

void BitcoinExchange::PutDataBase()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw (std::runtime_error("Error: could not open file."));
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::stringstream comma(line);
        std::string date;
        std::string value_str;
        float value;

        std::getline(comma, date, ',');
        std::getline(comma, value_str);
        std::stringstream(value_str) >> value;
        this->my_map.insert(std::make_pair(date, value));
    }
}

std::string BitcoinExchange::TrimInput(std::string str)
{
    size_t first;
    int last;

    first = str.find_first_not_of(" \t\n");
    if (first == std::string::npos)
        return ("");
    last = str.find_last_not_of(" \t\n");
    return (str.substr(first, last - first + 1));
}

void BitcoinExchange::CheckInputFile(std::string file_name)
{
    PutDataBase();
    std::ifstream file(file_name.c_str());
    if (!file.is_open())
        throw (std::runtime_error("Error: could not open file."));
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t found = line.find(" | ");
        if (found == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::stringstream pipe(line);
        std::string date;
        std::string value_str;

        std::getline(pipe, date, '|');
        std::getline(pipe, value_str);

        date = TrimInput(date);
        value_str = TrimInput(value_str);

        if (!CheckDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (CheckValue(value_str) == -1)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        else if (!CheckValue(value_str))
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        float result;

        result = MainWork(date, value_str);
        if (result == -1)
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        std::cout << date << " => " << value_str << " = " << result << std::endl;
    }
}

int BitcoinExchange::CheckDate(std::string date)
{
    std::string mouth_str;
    std::string day_str;
    int mouth;
    int day;

    if (date.size() != 10)
        return (0);
    if (date[4] != '-' || date[7] != '-')
        return (0);
    if (!isdigit(date[0]) || !isdigit(date[1]) || !isdigit(date[2]) || !isdigit(date[3]) 
            || !isdigit(date[5]) || !isdigit(date[6])
            || !isdigit(date[8]) || !isdigit(date[9]))
        return (0);
    mouth_str += date[5];
    mouth_str += date[6];
    std::stringstream(mouth_str) >> mouth;
    if (mouth > 12 || mouth < 1)
        return (0);
    day_str += date[8];
    day_str += date[9];
    std::stringstream(day_str) >> day;
    if (day > 31 || day < 1)
        return (0);
    return (1);
}

int BitcoinExchange::CheckValue(std::string value_str)
{
    float value;

    std::stringstream(value_str) >> value;
    if (value < 0)
        return (-1);
    else if (value > 1000)
        return (0);
    else
        return (1);
}

float BitcoinExchange::MainWork(std::string date, std::string value_str)
{
    float value;
    std::map<std::string, float>::iterator it;

    if (this->my_map.empty())
        return (-3);
    std::istringstream(value_str) >> value;
    it = this->my_map.lower_bound(date);
    if (it == my_map.end())
    {
        it--;
        return (it->second * value);
    }
    if (it->first == date)
        return (it->second * value);
    if ((it == my_map.begin()) && (date < it->first))
        return (-1);
    if (it->first > date)
    {
        it--;
        return (it->second * value);
    }
    return (-2);
}