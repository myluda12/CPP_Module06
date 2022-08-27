#include <iostream>


typedef struct Data
{
    int o;
} Data;

uintptr_t serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

int main()
{
    Data d;

    uintptr_t p;

    d.o = 5;
    
    std::cout << "SERIALIIIIZE ________ " << std::endl;
    std::cout << d.o << std::endl;
    
    p = serialize(&d);


    std::cout << "DESERIALIIIZE __________________" << std::endl;
    Data *za;

    za = deserialize(p);

    std::cout << za->o << std::endl;

}