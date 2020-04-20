#include <thread>
#include <iostream>
using namespace std;

void myFunction(){
	std::cout << "Hello World" << std::endl;
}

///////////
// Some of the times function will be return otherwise
//  main will return even before the fuction prints
///////
int main(){
std::thread t(myFunction);
return 0;
}


