
/**
 * @author Denim Patel
 * @brief Calculates the minimum sideways motion required
 * to reach to the given horizon
 * @date 22 Mar 2020
*/
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


void util(vector<int> cars, int horizon, int current_horizon,
            int current_position, int current_cost, int& cost){
    
    if(current_horizon>horizon){
        cout<<"reached to the end!! with cost = "<<current_cost<<endl;
        // update the results
        cost = min(cost, current_cost);
        return;
    }
    
    if (cars[current_horizon] == current_position){
        // obstacle at the current place    
        util(cars, horizon, current_horizon+1, (current_position+1)%3, current_cost+1, cost);
        util(cars, horizon, current_horizon+1, (current_position+2)%3, current_cost+1, cost);
    }
    else {
        // go forward
        util(cars, horizon, current_horizon+1, current_position, current_cost, cost);
    }
    
}


int min_cost(vector<int> cars) {
    int ans = 1e5;
    util(cars, cars.size()-1, 0, 1,  0, ans);
    return ans;
}


int main(){
    vector<int> cars = {0,0,2,2,2,2,2,2,2,2,1,1,1,1,1,1,0};
    int ans;
    ans = min_cost(cars);
    cout << " ans = " << ans << endl;
    return 0;
}
