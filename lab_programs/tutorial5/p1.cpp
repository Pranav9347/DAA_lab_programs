#include <iostream>
#include <vector>

std::pair<int, int> bs_insertion_sort(std::vector<int>& arr) {
    int comparisons = 0;
    int swaps = 0;
    //Binary search
    for (int i{1}; i < arr.size(); i++) {
        int key = arr[i];
        int left = 0;
        int right = i - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            comparisons++;
            if (arr[mid] < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        //Insertion sort
        for (int j{i}; j > left; j--) {
            arr[j] = arr[j - 1];
            swaps++;
        }
        arr[left] = key;
    }
    return std::make_pair(comparisons, swaps);
}

int main() {
    int n,x;
    std::vector<int> arr;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;
    std::cout << "Enter the array: ";
    for(int i{0}; i < n; i++)
    {
        std::cin >> x;
        arr.push_back(x);
    }
    std::pair<int, int> result = bs_insertion_sort(arr);
    std::cout << "Sorted array:";
    for (int num : arr) {
        std::cout << " " << num;
    }
    std::cout << std::endl;
    std::cout << "Number of comparisons: " << result.first << std::endl;
    std::cout << "Number of swaps: " << result.second << std::endl;
    return 0;
}

