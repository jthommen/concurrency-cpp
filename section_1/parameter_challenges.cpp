#include<iostream>
#include<thread>
#include<chrono>


void func_2(int& x)
{
  while(true)
  {
      try {
          std::cout << x << std::endl;
          std::this_thread::sleep_for(std::chrono::seconds(1));
      }
      catch (...)
      {
          throw std::runtime_error("this is a runtime error");
      }
  }  
}

void func_1()
{
    int x = 5; // scoped to func_1
    std::thread thread_2(func_2, std::ref(x)); // passing to func_2
    thread_2.detach();  // detaching thread_2
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "thread_1 finished execution\n";
    // thread_1 goes out of scope, freeing up memory of x used by thread_2
    // leading to exception
}

int main()
{
    std::thread thread_1(func_1);
    thread_1.join();
}