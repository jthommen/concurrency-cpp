#include<iostream>
#include<thread>
#include<chrono>


void func_1()
{
    std::cout << "This thread has id - " << std::this_thread::get_id() << std::endl;
}

void get_id_test()
{
    std::thread thread_1(func_1);
    std::thread thread_2(func_1);
    std::thread thread_3(func_1);
    std::thread thread_4;

    // works also outside of thread by passing correct thread object
    std::cout << "Thread 1 id: " << thread_1.get_id() << std::endl;
    std::cout << "Thread 2 id: " << thread_2.get_id() << std::endl;
    std::cout << "Thread 3 id: " << thread_3.get_id() << std::endl;
    std::cout << "Thread 4 id: " << thread_4.get_id() << std::endl;
    
    thread_1.join();
    thread_2.join();
    thread_3.join();

    std::cout << "Thread 3 id: " << thread_3.get_id() << std::endl;
}

int main()
{
    get_id_test();

    std::cout << "Number of hardware threads: " << std::thread::hardware_concurrency() << std::endl;

}

/* Other useful functions

std::this_thread::yield();
  Yield will give up the current time slice and re-insert the thread into
  the scheduling queue. The amount of time that expires until the thread is executed
  again is usually entirely dependent upon the scheduler.

std::thread::hardware_concurrency()
  Returns the number of concurrent thread supported by the implementation. The value
  should be considered only a hint.

*/