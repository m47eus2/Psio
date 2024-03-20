#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

double poly(double x, vector<double> p)
{
    double result=0;
    for(int i = 0; i<p.size(); i++)
    {
        result +=  p[i] * pow(x,i);
    }
    return result;
}

double zero_r(double bottom, double top, vector<double> p)
{
    double middle = (top+bottom) / 2;

    double bottom_value = poly(bottom, p);
    double middle_value = poly(middle, p);
    double top_value    = poly(top, p);
    
    if(top-bottom < 1e-9) return middle;
    else if(bottom_value * middle_value < 0) return zero_r(bottom, middle, p);
    else if(middle_value * top_value < 0) return zero_r(middle, top, p);
}

vector<double> zero(double x_min, double x_max, vector<double> p, double step)
{
    vector<double> roots;
    double x = x_min;
    for(int i = 0; i<(x_max-x_min)/step; i++)
    {
        //cout<<"Sprawdzanie: "<<x<<" "<<x+step<<endl;
        if(poly(x,p) * poly(x+step,p) == 0)
        {
            //cout<<"    Rozwiazanie na granicy: "<<x<<" "<<x+step<<endl;
            if(poly(x,p) == 0) roots.emplace_back(x);
        }
        else if(poly(x,p) * poly(x+step,p) < 0)
        {
            //cout<<"    Zmiana znaku: "<<x<<" "<<x+step<<endl;
            //cout<<zero_r(x, x+step, p)<<endl;
            roots.emplace_back(zero_r(x, x+step, p));
        }
        x += step;
    }
    return roots;
}


int main()
{
    int deg;
    vector<double> p;
    double input;
    double x, x_min, x_max, step;
    
    
    cin>>deg;
    for(int i = 0; i<=deg; i++)
    {
        cin>>input;
        p.emplace_back(input);
    }
    
    cin >> x >> x_min >> x_max >> step;
    
    double res = poly(x,p);
    vector<double> zeros = zero(x_min,x_max, p, step);
    
    cout << res << endl;
    for(int i  = 0; i<zeros.size();i++){
        cout<<zeros[i]<<endl;;
    }
   
    return 0;
}