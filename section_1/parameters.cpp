#include<thread>
#include<iostream>
#include<chrono>

void func_1(int x, int y)
{
    std::cout << "X + Y = " << (x+y) << std::endl;
}

void func_2(int& x)
{
    while(true)
    {
        std::cout << "Thread 1 value of X - " << x << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    int x = 9;
    std::cout << "Main thread of X - " << x << std::endl;

    std::thread thread_1(func_2, std::ref(x)); // param by value per default
    std::this_thread::sleep_for(std::chrono::seconds(3));
    
    x = 15;
    std::cout << "Main thread of X has changed to - " << x << std::endl;
    thread_1.join();
}