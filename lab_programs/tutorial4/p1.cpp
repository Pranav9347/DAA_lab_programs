#include <iostream>
#include <vector>

std::vector<std::vector<int>> list_all_subsets(std::vector<int> input_set) {
    int n = input_set.size();
    std::vector<std::vector<int>> all_subsets;
    
    for (int i = 0; i < (1 << n); i++) {
        std::vector<int> subset;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                subset.push_back(input_set[j]);
            }
        }
        all_subsets.push_back(subset);
    }
    return all_subsets;
}

int main() {
    std::vector<int> input_set = {1, 2, 3};
    std::vector<std::vector<int>> subsets = list_all_subsets(input_set);
    for (auto subset : subsets) {
        for (auto element : subset) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

