#include <thread>
#include <iostream>
#include <functional> // for std::ref

class PrintThis
{
public:
    void operator()() const
    {
        std::cout<<"this = "<<this<<std::endl;
    }
};

int main()
{
    PrintThis x;
    x();
    std::thread t(std::ref(x));  // this passes the same object
    t.join();
    std::thread t2(x);		// thus copies the object so the address printed will be different
    t2.join();
}
