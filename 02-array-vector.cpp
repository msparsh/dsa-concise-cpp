#include <iostream>
#include <vector>

int main()
{
    int arr_primes[6] = {2, 3, 5, 7, 11, 13};
    int arr_evens[7] = {2, 4, 6, 8, 10, 12, 14};

    std::cout << arr_evens[2] << arr_primes[3] << std::endl;

    std::vector<int> primes = {2, 3, 5, 7, 11, 13};
    primes.push_back(17);

    std::cout << "primes[0]: " << primes.front() << std::endl;
    std::cout << "primes[-1]: " << primes.back() << std::endl;

    std::cout << "Size of primes: " << primes.size() << std::endl;
    for (const int& p:primes){
        std::cout<<p<<"-";
    }
    std::cout<<std::endl;


}