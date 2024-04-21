#include <iostream> 
using namespace std; 

template<typename T>
  
class Complex { 
private: 
    T _real;
    T _imaginary;
public: 
    Complex(T real, T imaginary)
    {
        _real = real;
        _imaginary = imaginary;
    }

    Complex()
    {
        _real = 0;
        _imaginary = 0;
    }

    Complex operator+ (Complex &c)
    {
        _real = _real + c._real;
        _imaginary = _imaginary + c._imaginary;
        return *this;
    }

    Complex operator- (Complex &c)
    {
        Complex ret(_real - c._real, _imaginary - c._imaginary);
        return ret;
    }

    Complex operator* (Complex &c)
    {
        Complex ret((_real * c._real)+(_imaginary * c._imaginary * -1), (_real * c._imaginary)+(_imaginary * c._real));
        return ret;
    }

    Complex operator= (Complex c)
    {
        _real = c._real;
        _imaginary = c._imaginary;
        return *this;
    }

    friend ostream& operator<<(ostream& os, Complex& c)
    {
        os<<c._real<<"+"<<c._imaginary<<"i";
        return os;
    }
}; 
  
// DO NOT MODIFY ANYTHING BELOW, MAY RESULT WITH FAILED HOMEWORK
int main() 
{   
    Complex<int> result1;
    Complex<double> result2;
    int re,im;
    double re1,im1;
    
    std::cin>>re;
    std::cin>>im;
    
    Complex<int> c1(re,im);
    
    std::cin>>re;
    std::cin>>im;
    
    Complex<int> c2(re,im);
    
    std::cin>>re1;
    std::cin>>im1;
    
    Complex<double> c3(re1,im1);
    
    std::cin>>re1;
    std::cin>>im1;
    
    Complex<double> c4(re1,im1);
    
    result1 = c1 * c2;
    
    std::cout<< result1 << std::endl;
    
    result2 = c3 + c4;
    
    std::cout<< result2 << std::endl;
    
    return 0; 
}