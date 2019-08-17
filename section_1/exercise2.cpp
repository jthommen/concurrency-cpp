#include<iostream>
#include<thread>
#include<chrono>

void cleaning()
{
    // non blocking (detach)
    std::cout << "Cleaning started.\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Cleaning finished.\n";
}

void fullSpeedAhead()
{
    // blocking (join)
    std::cout << "Full Speed Ahead started.\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Full Speed Ahead finished.\n";
}

void fullStop()
{
    // blocking (join)
    std::cout << "Full stop started.\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Full stop finished.\n";
}

int main()
{

    std::cout << "Welcome to your ship captain!\n"
        << "The following commands are available:\n"
        << "1 - Clean the ship\n"
        << "2 - Full speed ahead\n"
        << "3 - Full stop\n"
        << "100 - Autopilot (exit program)\n";

    int cmnd = 0;

    while(cmnd != 100) {
        std::cout << "\nPlease issue your command: ";
        std::cin >> cmnd;

        switch(cmnd)
        {
            case 1:
            {
                std::thread cleaningCrew(cleaning);
                cleaningCrew.detach();
                break;
            }
            case 2:
            {
                std::thread engineCrew(fullSpeedAhead);
                engineCrew.join();
                break;
            }
            case 3:
            {
                std::thread engineCrew(fullStop);
                engineCrew.join();
                break;
            }
            case 100 :
                break;
            default:
                std::cout << "Invalid order\n";
                break;
        }
    }

    std::cout << "Commands executed captain!\n";

}
