#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int product_of_digits(int n)
{
    n = abs(n);
    int product = 1;
    while(n>0)
    {
        product *= n%10;
        n /= 10;
    }
    return product;
}

int count_even_products_and_sort_list(list<int> &lista) {
    lista.sort([](int x, int y){return x>y;});
    return count_if(lista.begin(), lista.end(), [](int n){return (product_of_digits(n)%2)==0;});
}

// PROSZE NIE EDYTOWAC NIC PONIZEJ, MOZE SKUTKOWAC NIEZALICZENIEM ZADANIA
int main() {
    std::list<int> lista;
    int n;
    while(std::cin>>n)
        lista.push_back(n);

    if (*lista.begin() != 13)
    {
        std::cout << count_even_products_and_sort_list(lista) << std::endl;
        
    }
    else
    {
        count_even_products_and_sort_list(lista);
        for(auto i : lista) {
            std::cout << i << " ";
    }
    }
}