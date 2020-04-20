#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

float findAngle (int hour, int minute){
    int minuteAngle = minute * 6;
    int hourAnglePosition = 30 * hour + 0.5 * minute;
    
    int ans = abs(minuteAngle - hourAnglePosition);
    ans = min(ans, 360-ans);
    return ans;
}

int main()
{
    // input
    int hour = 6;
    int minute = 30;
    
    // calculate
    float angle = findAngle(hour, minute);
    
    // display
    cout << "angle between " << hour << " and " << minute <<" is " << angle << endl;

    return 0;
}