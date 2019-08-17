#include<iostream>
#include<thread>

void hello()
{
    std::cout << "Hello from the function thread - "
        << std::this_thread::get_id() << std::endl;
}

class callable_class {

    public:
        void operator()()
        {
            std::cout << "Hello from the class thread  - " 
                << std::this_thread::get_id() << std::endl;
        }
};

int main()
{
    // Launching thread and handing it a function
    std::thread thread1(hello);

    // Spawning thread from callable class
    callable_class obj;
    std::thread thread2(obj);

    // Launchning thread from lambda expression
    std::thread thread3([]
    {
        std::cout << "Hello from the lambda thread - " << std::this_thread::get_id() << std::endl;
    });

    // Joining the launched threads with the main thread
    thread1.join();
    thread2.join();
    thread3.join();

    std::cout << "Hello from the main thread - " << std::this_thread::get_id() << std::endl;

}
