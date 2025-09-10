#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#include <iostream>
#include <cmath>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	public:
		Serializer();
		~Serializer();
		Serializer(const Serializer &s);
		Serializer& operator=(const Serializer &s);
		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};

#endif