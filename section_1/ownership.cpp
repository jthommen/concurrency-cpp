#include<iostream>
#include<thread>
#include<chrono>

void func_1()
{

}

void func_2()
{

}

int main()
{
    try
    {
        std::thread thread_1(func_1);

        // Moves ownership of a thread, thread can only have one owner
        std::thread thread_2 = std::move(thread_1);

        // Implicit move call
        thread_1 = std::thread(func_2);

        std::thread thread_3(func_1);
        // gives an error, thread_1 has already assiged a thread
        //thread_1 = std::move(thread_3);

        thread_1.join();
        thread_2.join();
        thread_3.join();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}