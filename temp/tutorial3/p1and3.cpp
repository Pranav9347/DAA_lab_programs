#include <iostream>
#include <algorithm>

using namespace std;

class Tutorial3 {
public:
    void run() {
        int choice;
        do {
            cout << "Menu:\n";
            cout << "1. Find Duplicates in an Array\n";
            cout << "2. Find Missing Integer in an Array\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    findDuplicatesMenu();
                    break;
                case 2:
                    findMissingIntegerMenu();
                    break;
                case 3:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice. Please select a valid option.\n";
            }
        } while (choice != 3);
    }

private:
    void findDuplicatesMenu() {
        int size;
        cout << "Enter the size of the array: ";
        cin >> size;
        int A[size];
        cout << "Enter the elements: ";
        for (int i = 0; i < size; ++i) {
            cin >> A[i];
        }
        findDuplicates(A, size);
    }

    void findMissingIntegerMenu() {
        int size;
        cout << "Enter the size of the array: ";
        cin >> size;
        int A[size];
        cout << "Enter the elements: ";
        for (int i = 0; i < size; ++i) {
            cin >> A[i];
        }
        int missing = findMissingInteger(A, size);
        cout << "Missing Integer: " << missing << endl;
    }



    void findDuplicates(int A[], int size) {
        const int maxElement = *max_element(A, A + size);
        int frequency[maxElement + 1] = {0};

        for (int i = 0; i < size; ++i) {
            frequency[A[i]]++;
        }

        for (int i = 0; i <= maxElement; ++i) {
            if (frequency[i] > 1) {
                cout << "Duplicate: " << i << ", Multiplicity: " << frequency[i] << endl;
            }
        }
    }

    int findMissingInteger(int A[], int size) {
        int totalSum = (size * (size + 1)) / 2;
        int arraySum = 0;

        for (int i = 0; i < size; ++i) {
            arraySum += A[i];
        }

        return totalSum - arraySum;
    }


};

int main() {
    Tutorial3 tutorial;
    tutorial.run();
    return 0;
}
