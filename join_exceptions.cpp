#include<iostream>
#include "lib/common.hpp"

void foo()
{

}

void other_operations()
{
    std::cout << "this is another operation\n";
    throw std::runtime_error("this is a runtime error");
}

int main()
{
    std::thread foo_thread(foo);
    thread_guard tg(foo_thread);
    try
    {
        other_operations();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}