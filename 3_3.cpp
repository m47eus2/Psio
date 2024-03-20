#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void find_min_max(const list<int> &list, int &min, int&max){
    min = *min_element(list.begin(), list.end());
    max = *max_element(list.begin(), list.end());
}

void count_value(const list<int> &list, const int &value, int &counter){
    counter = count_if(list.begin(), list.end(), [value](int x){return x==value;});
}

void sort_list(list<int> &list){
    list.sort([](int x, int y){return abs(x)>abs(y);});
}

void find_and_erase(list<int> &list, const int &to_find){
    list.erase(find(list.begin(), list.end(),to_find));
}


int main()
{
    
    list<int> test_list;
    int to_find, to_count,input, min, max, counter;
    cin >> to_count;
    cin >> to_find;
    while (cin >> input)
        test_list.emplace_back(input);
        
    find_min_max(test_list, min, max);
    cout << min << endl;
    cout << max << endl;
    
    count_value(test_list,to_count,counter);
    cout << counter << endl;
    
    sort_list(test_list);
    
    find_and_erase(test_list, to_find);
    
    for (auto it = test_list.begin(); it!=test_list.end();it++) {
        cout << *it << endl; }
    
    
    return 1;
}