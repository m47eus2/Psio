#include <iostream>
#include <math.h>
#include <string>

using namespace std;

float check_angle(string input);

int main()
{
    string input;
    float angle;
    cin >> input;
    angle = check_angle(input);
    std::cout<<angle;
}

float check_angle(string input)
{
    string hour = input.substr(0,2);
    string minute = input.substr(3, 2);

    int hour_degree = stoi(hour)*30;
    int minute_degree = stoi(minute)*6;

    if(hour_degree >= 360) hour_degree -= 360;
    if(minute_degree >= 360) hour_degree -= 360;

    int degrees;
    if(hour_degree - minute_degree < 180) degrees = hour_degree - minute_degree;
    else degrees = 180 - (hour_degree - minute_degree);
    if(degrees < 0) degrees *= -1;

    if(input.substr(5) == "d") return degrees;

    else if(input.substr(5) == "r")
    {
        return round((degrees/180.0*3.14)*100)/100;
    }
}