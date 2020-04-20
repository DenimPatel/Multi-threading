#include <thread>
#include <iostream>

using namespace std;

void myFunction(){
	cout<< "Hello World "<<endl;
}

int main(){
std::thread t(myFunction);
t.join(); // this makes the code to wait for
          // thread t to complete its task
return 0;
}
