#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default Constructor Called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor Called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &s)
{
	(void)s;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &s)
{
	(void)s;
	return (*this);
}

void ScalarConverter::convert(std::string literal)
{
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else
	{
		std::istringstream iss(literal);
		double d;
		iss >> d;
		if (std::isnan(d) || d <= 0 || d > 127)
			std::cout << "char: Non displayable" << std::endl;
		else if (d < 32 || d == 127)
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(d) << std::endl;
		if (std::isnan(d) || std::isinf(d))
		{
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
		else
		{
			std::cout << "int: " << static_cast<int>(d) << std::endl;
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
		}
	}
}
