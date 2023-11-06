#include <iostream>
#include <vector>
#include <random>

using namespace std;

vector<int> bubble_sort(vector<int>& arr, int low, int high) {
    for (int i = high; i > low; i--) {
        bool swapped = false;
        for (int j = low; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    return arr;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

vector<int> quick_sort(vector<int>& arr, int low, int high, int threshold) {
    if (low < high) {
        if (high - low + 1 < threshold) {
            return bubble_sort(arr, low, high);
        }
        int pivot_index = partition(arr, low, high);
        quick_sort(arr, low, pivot_index - 1, threshold);
        quick_sort(arr, pivot_index + 1, high, threshold);
    }
    return arr;
}

vector<int> hybrid_sort(vector<int>& arr, int threshold) {
    return quick_sort(arr, 0, arr.size() - 1, threshold);
}

int main() {
    vector<int> arr(2000);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10000);
    for (int i = 0; i < 2000; i++) {
        arr[i] = dis(gen);
    }

    int threshold = 30;

    vector<int> sorted_arr = hybrid_sort(arr, threshold);
    std::cout << "The sorted array: ";
    for(int i{0}; i < sorted_arr.size(); i++)
        std::cout << sorted_arr[i] << " ";
    return 0;
}

