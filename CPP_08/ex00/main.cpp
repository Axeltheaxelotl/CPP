#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(0);
    vec.push_back(4);
    vec.push_back(3);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 6);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}