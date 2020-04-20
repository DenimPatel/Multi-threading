#include <thread>
#include <iostream>
#include <string>

void greeting(std::string const& message)
{
    std::cout<<message<<std::endl;
}

int main()
{
    // std::thread t(std::bind(greeting,"hi!"));
		// Or
    std::thread t(greeting,"hi!");
    t.join();
    return 0;
}
