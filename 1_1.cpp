#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double pi_leibniz(double s);

int main()
{
    double stop_at;
    cin >> stop_at;
    double pi_approx = pi_leibniz(stop_at);
    std::cout << pi_approx;
}

double pi_leibniz(double s)
{
    double pi = 1;

    int n = 3;
    while(true)
    {
        if(1.0/n >= s) pi -= 1.0/n;
        else return pi*4;
        if(1.0/(n+2) >= s) pi += 1.0/(n+2);
        else return pi*4;
        n += 4;
    }
}