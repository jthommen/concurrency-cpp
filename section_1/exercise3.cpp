#include<chrono>
#include<thread>
#include<iostream>
#include<queue>

void cleaner_crew(std::queue<int>& q)
{
    while(true)
    {
        if(!q.empty())
        {
            q.pop();
            std::cout << "Cleaner starting...\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "...cleaner finished.\n";
        } else {
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
}

void engine_crew(std::queue<int>& q)
{
    while(true)
    {
        if(!q.empty())
        {
            int order = q.front();
            switch(order)
            {
                case 2:
                    std::cout << "Engine full speed ahead\n";
                    break;
                case 3:
                    std::cout << "Engine full stop\n";
                    break;
            }
            q.pop();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        } else {
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
}

int main()
{
    std::cout << "Welcome to your ship captain!\n"
        << "The following commands are available:\n"
        << "1 - Clean the ship\n"
        << "2 - Full speed ahead\n"
        << "3 - Full stop\n"
        << "100 - Autopilot (exit program)\n";

    std::queue<int> cleaner_queue;
    std::queue<int> engine_queue;

    std::thread cleaner_thread(cleaner_crew, std::ref(cleaner_queue));
    std::thread engine_thread(engine_crew, std::ref(engine_queue));

    cleaner_thread.detach();
    engine_thread.detach();

    int cmd = 0;

    while(cmd != 100)
    {
        std::cout << "\nPlease issue your command: ";
        std::cin >> cmd;

        if(cmd == 1) { cleaner_queue.push(cmd); }
        else if(cmd == 2 || cmd == 3) engine_queue.push(cmd);
        else if(cmd == 100) exit(0);
        else std::cout << "Invalid order\n";

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

}
