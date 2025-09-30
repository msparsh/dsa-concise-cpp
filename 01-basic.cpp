#include <iostream>

int add(int a, int b);

int main() {
    int a = 5;
    char b = 'B';
    bool c = true;
    std::string d = "Hello, World!";
    bool e = false;

    std::cout << "everything : " << a << b << c << d << std::endl;

    if (a <= 5) {
        std::cout << "a is leq 5" << std::endl;
    }
    else {
        std::cout << "a is greater than 5";
    }

    if (c) {
        std::cout << "c is true" << std::endl;
    }
    if (e) {
        std::cout << "e is true" << std::endl;
    }
    else if (not e) {
        std::cout << "e is not true" << std::endl;
    }

    for (int i = 0; i < 10; i = i + 2) {
        std::cout << i << "-_-";
    }
    std::cout << std::endl;

    std::cout << "10 + 20 is " << add(10, 20) << std::endl;

    int l[5] = {10, 100, 1000, 10000, 100000};
    int *ptr_of_first = &l[0];

    std::cout << l[0] << std::endl;
    std::cout << *ptr_of_first << std::endl;

    std::cout << "DONE DONE DONE" << std::endl;
}

int add(int a, int b) {
    return a + b;
}