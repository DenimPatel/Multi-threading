#include <thread>
#include <iostream>

std::mutex m;
unsigned counter=0;

unsigned increment()
{
    std::lock_guard<std::mutex> lk(m);
    return ++counter;
}
void query()
{
    std::lock_guard<std::mutex> lk(m);
    std::cout << counter;
}

int main(){

    std::thread t1(increment);
    std::thread t2(query);

    t1.join();
    t2.join();
    
    return 0;
}