#include <iostream>
#include <vector>

int sum_of_digits(int n) {
    if (n == 0) {
        return 0;
    }
    return n % 10 + sum_of_digits(n / 10);
}

int sum_of_repeated_digits(int n) {
    std::vector<int> l(10, 0);
    while (n != 0) {
        l[n % 10] += 1;
        n /= 10;
    }
    int s = 0;
    for (int i = 0; i < 10; i++) {
        if (l[i] > 1) {
            s += i * (l[i] - 1);
        }
    }
    return s;
}

int main() {
    while (true) {
        int n;
        std::cout << "Enter n: ";
        std::cin >> n;
        int option;
        std::cout << "(1) Sum of digits of " << n << std::endl;
        std::cout << "(2) Sum of distinct digits of " << n << std::endl;
        std::cout << "Enter option: ";
        std::cin >> option;
        if (option == 1) {
            std::cout << "Sum of digits of " << n << " is: " << sum_of_digits(n) << std::endl;
        } else if (option == 2) {
            std::cout << "Sum of distinct digits of " << n << " is: " << sum_of_digits(n) - sum_of_repeated_digits(n) << std::endl;
        }
    }
    return 0;
}

