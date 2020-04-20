#include <thread>
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class SayHello
{
    public:
        void greeting(std::string message) const
        {
            std::cout<<message<<std::endl;
        }
};

/* 
Make sure that the object "x" outlives than the thread 
so for that generally object is initialized in heap memory
*/ 
int main(){
    // SayHello x;
    // std::thread t(&SayHello::greeting, &x, "how are you?");
    
    // OR

    // SayHello* x = new SayHello();
    // shared_ptr<SayHello> x(new SayHello());
    shared_ptr<SayHello> x = make_shared<SayHello> ();
    
    std::thread t(&SayHello::greeting, x, "how are you?");
    t.join();
}


