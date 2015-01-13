#include "Value.h"
#include <iostream>
#include <string>

int main()
{
    ValueBase::ValueBasePtr valuePtr(new Value<int>(10));
    JaggedArray a;
    a.add(10);
    a.add(std::string("haha"));

    int value = a.get<int>(0);
    //std::string ch = a.get<std::string>(1);
    int ch = a.get<int>(1);
    std::cout << value <<  '\t' << ch << std::endl;
    return 0;
}
