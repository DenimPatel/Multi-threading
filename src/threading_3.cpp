#include <thread>
#include <iostream>

using namespace std;

class SayHello{
public:
	void operator()() const{
		cout<< "Hello World" <<endl;
	}

};

int main(){
    // std::thread t((SayHello())); or
    std::thread t{SayHello()};
    t.join();
    return 0;
}
