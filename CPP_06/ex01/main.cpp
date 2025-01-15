#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data ptr2;
    ptr2.name = "Michaela Mustermann";
    ptr2.value = 42;

    Data ptr;
    ptr.name = "Max Mustermann";
    ptr.value = 42;

    std::cout << "Here is the original structs:" <<
                "\n\taddress: " << &ptr <<
                "\n\tname: " << ptr.name <<
                "\n\tvalue: " << ptr.value <<
                "\n\taddress next: " << &ptr2 <<
    std::endl;
    std::cout << "\taddress ptr2: " << &ptr2 <<
                "\n\tname: " << ptr2.name <<
                "\n\tvalue: " << ptr2.value <<
    std::endl << std::endl;

    Serializer a;

    Data *reserialized_struct = a.unserialize(a.serialize(&ptr));

    std::cout << "Here is the reserialized structs:" <<
                "\n\taddress: " << reserialized_struct <<
                "\n\tname: " << reserialized_struct->name <<
                "\n\tvalue: " << reserialized_struct->value <<
                "\n\taddress next: " << &ptr2 <<
    std::endl;
    std::cout << "\taddress ptr2: " << &ptr2 <<
                "\n\tname: " << ptr2.name <<
                "\n\tvalue: " << ptr2.value <<
    std::endl << std::endl;

    return 0;
}