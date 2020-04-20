#include <iostream>
#include <thread>
#include <future>

using namespace std;

std::mutex m;
unsigned counter = 0;

int increment()
{
    std::lock_guard<std::mutex> lk(m);
    return ++counter;
}
int query()
{
    std::lock_guard<std::mutex> lk(m);
    return counter;
}

int main(){

// how to get return the output from the thread??
// using std::future<datatype>

// async spins up new thread as soon as it is executed
    std::future<int> a = std::async(increment);

// deferred spins up new thread only when get is called
// which is better when for query application
    std::future<int> b = std::async(launch::deferred, query);

// .get() provides the return data from thread
// .valid() can be used as flag to check whether result is 
// accessed before and now valid or not
    if (a.valid()) {
        cout<<"after increment = "<<a.get()<<" query = "<<b.get()<<endl;
    }

    return 0;
}