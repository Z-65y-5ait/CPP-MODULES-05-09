#include "Serializer.hpp"

int main()
{
    Data *d = new Data();
    Serializer s;

    d->integer = 2;
    uintptr_t raw = s.serialize(d);
    Data* p = s.deserialize(raw);

    std::cout << "Original: " << d->integer << "\n";
    std::cout << "From pointer: " << p->integer << "\n";
}
