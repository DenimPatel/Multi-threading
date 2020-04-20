#include <thread>
#include <iostream>
#include <string>

class Greeting{
    std::string message;
public:
    explicit Greeting(std::string const& message_):
        message(message_){}
    void operator()() const{
        std::cout<<message<<std::endl;
    }
};

int main(){
    std::thread t{Greeting("goodbye")};
    t.join();
    return 0;
}

