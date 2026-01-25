#include "iter.hpp"

int main()
{
    int numbers[5] = {1, 2, 3, 4, 5};
    iter(numbers, 5, printElement);

    std::string words[3] = {"hello", "world", "cpp"};
    iter(words, 3, printElement);

    return 0;
}