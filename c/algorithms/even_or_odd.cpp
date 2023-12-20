#include <iostream>

int main()
{
    long num;
    std::cout << "Enter a number" << std::endl;
    std::cin >> num;
    int rem = num % 2;
    
    if(rem == 0)
        std::cout << "Even" << std::endl;
    else
        std::cout << "Odd" << std::endl;
}