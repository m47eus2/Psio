#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(std::vector<double>& vec)
{
    int size = vec.size();
    bool zmiana = 1;
    int i = 0;
    
    while(zmiana)
    {
        i=0;
        zmiana=0;
        while(i<size-1)
        {
            if(vec[i]>vec[i+1])
            {
                double m = vec[i];
                vec[i] = vec[i+1];
                vec[i+1]=m;
                zmiana=1;
            }
            i = i + 1;
        }
        size = size - 1;
    }
}

int main()
{
    std::vector<double> vec;
    int n;
    std::cin >> n;
    double number;
    for(int i = 0; i < n; ++i)
    {
        std::cin >> number;
        vec.push_back(number);
    }
    
    bubble_sort(vec);
    
    for(size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << std::endl;
    }
    return 0;
}