#include <iostream>

#include "shared_ptr.h"

template<typename PTR>
void print(PTR ptr)
{
    std::cout << *ptr << std::endl;
}

// shared ptr tester
int main()
{
    using namespace kli;
    
    SharedPtr<int> num1{new int{100}};
    
    SharedPtr<int> num2;
    num2 = num1;
    
    SharedPtr<int> num3{num2};
    
    print(num3);
}
