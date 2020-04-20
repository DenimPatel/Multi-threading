#include <iostream>
#include <vector>
using namespace std;

int main(){

/*
Theory with code:
"[]" is called caputure list
"()" is parameter list 
*/

    // example definition of lambda fucntion
    auto lambda_func = []() {
        cout << "This is coming from lambda function " << endl;
    };
    lambda_func();

    // Lambda turns the function into objects
    auto lam1 = lambda_func;
    lam1();

    // lambda function with parameters using camputure list
    int val1 = 5;
    int val2 = 7;
    auto sum1 = [&]() { // & signifies the parameters are passed by reference
        return val1 + val2;
    };

    auto sum2 = [=]() { // & signifies the parameters are passed by value
        return val1 + val2;
    };

    // lambda function with parameters using parameter list
    int val = 6;
    auto lam2 = [](int val) {
        return val * 5;
    };

    /*
    As you can see lambda doesn't require return type definition
    It infers it automatically
    To specity the return datatype use "->datatype" as follows
    */
    auto lam_func = []()->float {
    };

    // use of lambda function
    vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int compare = 5;
    auto a = find_if(data.begin(), data.end(), [&](int value){
        return value == compare;
    });
    cout <<"Found the value @ " << a - data.begin() << endl;

    return 0;
};