#include <iostream>
#include <climits>

using namespace std;

class Tutorial1 {
public:
    void run() {
        int choice;
        do {
            cout << "Menu:\n";
            cout << "1. Sum of Digits and Sum of Distinct Digits\n";
            cout << "2. Prime Factors and Factorization\n";
            cout << "3. Minimum and Second Minimum\n";
            cout << "4. Square Root\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    sumOfDigitsAndDistinctDigits();
                    break;
                case 2:
                    primeFactorsAndFactorization();
                    break;
                case 3:
                    minAndSecondMin();
                    break;
                case 4:
                    computeSquareRoot();
                    break;
                case 5:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice. Please select a valid option.\n";
            }
        } while (choice != 5);
    }

private:
    void sumOfDigitsAndDistinctDigits() {
        int n;
        cout << "Enter an integer: ";
        cin >> n;
        cout << "Sum of digits: " << sumOfDigits(n) << endl;
        cout << "Sum of distinct digits: " << sumOfDistinctDigits(n) << endl;
    }

    void primeFactorsAndFactorization() {
        int n;
        cout << "Enter an integer: ";
        cin >> n;

        cout << "Prime factors: ";
        primeFactors(n);

        cout << "Prime factorization: ";
        primeFactorization(n);

        cout << "All factors: ";
        allFactors(n);

        int sumOfAllFactors = sumAllFactors(n);
        cout << "Sum of all factors: " << sumOfAllFactors << endl;
    }

    void minAndSecondMin() {
        int n;
        cout << "Enter the number of elements: ";
        cin >> n;
        int arr[n];
        cout << "Enter the elements: ";
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        findMinAndSecondMin(arr, n);
    }

    void computeSquareRoot() {
        double x;
        cout << "Enter a natural number: ";
        cin >> x;
        double sqrtResult = sqrtApproximation(x);
        cout << "Square root of " << x << " is approximately: " << sqrtResult << endl;
    }

    int sumOfDigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int sumOfDistinctDigits(int n) {
        int sum = 0;
        bool digits[10] = {false};
        while (n > 0) {
            int digit = n % 10;
            if (!digits[digit]) {
                sum += digit;
                digits[digit] = true;
            }
            n /= 10;
        }
        return sum;
    }

    void primeFactors(int n) {
        cout << "Prime factors: ";
        for (int i = 2; i * i <= n; ++i) {
            while (n % i == 0) {
                cout << i << " ";
                n /= i;
            }
        }
        if (n > 1) {
            cout << n << " ";
        }
        cout << endl;
    }

    void primeFactorization(int n) {
        cout << "Prime factorization: ";
        for (int i = 2; i * i <= n; ++i) {
            int count = 0;
            while (n % i == 0) {
                n /= i;
                ++count;
            }
            if (count > 0) {
                cout << i << "^" << count << " ";
            }
        }
        if (n > 1) {
            cout << n << "^1 ";
        }
        cout << endl;
    }

    void allFactors(int n) {
        cout << "All factors: ";
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                cout << i << " ";
                if (i != n / i) {
                    cout << n / i << " ";
                }
            }
        }
        cout << endl;
    }

    int sumAllFactors(int n) {
        int sum = 0;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                sum += i;
                if (i != n / i) {
                    sum += n / i;
                }
            }
        }
        return sum;
    }

    void findMinAndSecondMin(int arr[], int n) {
        int minVal = INT_MAX;
        int secondMinVal = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (arr[i] < minVal) {
                secondMinVal = minVal;
                minVal = arr[i];
            } else if (arr[i] < secondMinVal && arr[i] != minVal) {
                secondMinVal = arr[i];
            }
        }
        cout << "Minimum: " << minVal << endl;
        cout << "Second Minimum: " << secondMinVal << endl;
    }

    double sqrtApproximation(double x) {
       int freq=0;
       double val=1;
       while(freq!=20)
       {
           freq++;
           val=(val+x/val)*0.5;

       }
       return val;
    }
};

int main() {
    Tutorial1 tutorial;
    tutorial.run();
    return 0;
}
