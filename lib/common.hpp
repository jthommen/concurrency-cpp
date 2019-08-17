#include<vector>
#include<thread>

class thread_guard {

private:
    std::thread& t;

public:
    // contructor taking thread object and assigning to local reference
    // explicit prevents implicit type conversion at object construction (PPP 18)
    explicit thread_guard(std::thread& _t): t(_t) { }

    // destructor
    ~thread_guard()
    {
        if(t.joinable())
        {
            t.join();
        }
    }

    // Don't need copy constructor and copy assignment operator
    thread_guard(const thread_guard&) = delete;
    thread_guard & operator= (const thread_guard&) = delete;

};