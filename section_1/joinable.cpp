#include<iostream>
#include<thread>

void test()
{
    std::cout << "Hello from test\n";
}

int main()
{

    // Properly constructed thread (with callable object param)
    std::thread thread1(test);

    if(thread1.joinable())
    {
        std::cout << "Thread1 is joinable\n";
    } 
    else
    {
        std::cout << "Thread1 is not joinable\n";
    }

    thread1.join();

    if(thread1.joinable())
    {
        std::cout << "Thread1 is joinable\n";
    } 
    else
    {
        std::cout << "Thread1 is not joinable\n";
    }

    // Not properly constructed thread (without callable object param)
    std::thread thread2;
    if(thread2.joinable())
    {
        std::cout << "Thread2 is joinable\n";
    } 
    else
    {
        std::cout << "Thread2 is not joinable\n";
    }
    
}