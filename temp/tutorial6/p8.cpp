// 2 pointers method:
#include <iostream>
#include <vector>

int trapWater(std::vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int leftMax = 0;
    int rightMax = 0;
    int trappedWater = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] > leftMax) {
                leftMax = height[left];
            } else {
                trappedWater += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] > rightMax) {
                rightMax = height[right];
            } else {
                trappedWater += rightMax - height[right];
            }
            right--;
        }
    }

    return trappedWater;
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the elevation map: ";
    std::cin >> n;

    std::vector<int> elevationMap(n);
    std::cout << "Enter the elevation values: ";
    for (int i = 0; i < n; i++) {
        std::cin >> elevationMap[i];
    }

    int result = trapWater(elevationMap);
    std::cout << "Total trapped water: " << result << std::endl;

    return 0;
}
