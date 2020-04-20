#include <thread>
#include <iostream>

void write_sum (int x, int y)
{
    std::cout<<x<<" + "<<y<<" = "<<(x+y)<<std::endl;
}

int main()
{
    std::thread t(write_sum,123,456);
    t.join();
    return 0;
}
