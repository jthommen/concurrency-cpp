#include<iostream>
#include<thread>

void test()
{
    std::cout << "Hello from test\n";
}

void functionA()
{
    std::cout << "Hello from functionA\n";
    std::thread threadC(test);
    threadC.join();
}

void functionB()
{
    std::cout << "Hello from functionB\n";
}

int main()
{
    std::thread threadA(functionA);
    std::thread threadB(functionB);

    threadA.join();
    threadB.join();
    std::cout << "Hello from main\n";

}