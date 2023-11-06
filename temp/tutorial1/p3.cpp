#include <iostream>
#include <vector>
#include <cmath>

int index_of_min(std::vector<int>& arr) {
    int x = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[x] > arr[i]) {
            x = i;
        }
    }
    return x;
}

int Smin(std::vector<int>& arr, int x) {
    std::vector<std::vector<int>> array_list;
    for (int i = 0; i < std::ceil(std::log2(arr.size())); i++) {
        std::vector<int> l;
        array_list.push_back(l);
    }
    array_list.push_back(arr);
    for (int i = 0; i < array_list.size() - 1; i++) {
        int a = 0, b = 1;
        int c = array_list.size() - 2 - i;
        while (true) {
            if (a == array_list[c + 1].size() - 1) {
                array_list[c].push_back(array_list[c + 1][a]);
                break;
            }
            if (a > array_list[c + 1].size() - 1) {
                break;
            }
            else {
                array_list[c].push_back(std::min(array_list[c + 1][a], array_list[c + 1][b]));
            }
            a += 2;
            b += 2;
        }
    }
    std::vector<int> sarray;
    for (int i = 0; i < array_list.size() - 1; i++) {
        if (x % 2 == 0) {
            sarray.push_back(array_list[array_list.size() - 1 - i][x + 1]);
        }
        else {
            sarray.push_back(array_list[array_list.size() - 1 - i][x - 1]);
        }
        x = x / 2;
    }
    return sarray[index_of_min(sarray)];
}

int main() {
    int n;
    std::cout << "Enter array size: ";
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int x = index_of_min(arr);
    std::cout << "Min: " << arr[x] << std::endl;
    std::cout << "SMin: " << Smin(arr, x) << std::endl;
    return 0;
}

