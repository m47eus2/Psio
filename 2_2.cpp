#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<double> &v, double search_for);

int main()
{
    vector<double> v;
    double input, search_for;
    cin >> search_for;
    while (cin >> input)
        v.emplace_back(input);
    int result = binary_search(v, search_for);
    cout << result;
}

int binary_search(vector<double> &v, double search_for)
{
    int shift = 0;
    while(v.size()>1)
    {
        double middle_value = v[v.size()/2];
        if(middle_value == search_for) return v.size()/2+shift;
        else if(middle_value > search_for) 
        {
            vector<double> left (v.begin(), v.end()-v.size()/2);
            v = left;
        }
        else 
        {
            vector<double> right (v.begin() + v.size()/2, v.end());
            shift += v.size()/2;
            v = right;
        }
    }
    return -1;
}