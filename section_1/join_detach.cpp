#include<thread>
#include<iostream>
#include<chrono>

void functionA()
{
    // Put thread to sleep for 5000 milliseconds
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout << "Hello from functionA\n";
}

void functionB()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout << "Hello from functionB\n";
}

int main()
{   
    // thread creation
    std::thread threadA(functionA);
    std::thread threadB(functionB);

    threadA.detach();
    std::cout << "This is after threadA detach\n"; //main thread continues immediately

    threadB.join();
    std::cout << "This is after threadB join\n"; // main thread waits until threadB exits

}
