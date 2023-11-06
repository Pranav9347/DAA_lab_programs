#include <iostream>
#include <vector>

int findThirdMax(std::vector<int>& nums, int& comparisons) {
    int firstMax = INT_MIN;
    int secondMax = INT_MIN;
    int thirdMax = INT_MIN;

    for (int i = 0; i < nums.size(); ++i) {
        comparisons++;  // Count each comparison

        if (nums[i] > firstMax) {
            thirdMax = secondMax;
            secondMax = firstMax;
            firstMax = nums[i];
        } else if (nums[i] < firstMax && nums[i] > secondMax) {
            thirdMax = secondMax;
            secondMax = nums[i];
        } else if (nums[i] < secondMax && nums[i] > thirdMax) {
            thirdMax = nums[i];
        }
    }

    return thirdMax;
}

int main() {
    std::vector<int> nums = {4, 1, 3, 6, 5, 7, 2};
    int comparisons = 0;

    int thirdMax = findThirdMax(nums, comparisons);

    if (thirdMax != INT_MIN) {
        std::cout << "The third maximum element is: " << thirdMax << std::endl;
    } else {
        std::cout << "No third maximum element found." << std::endl;
    }

    std::cout << "Number of comparisons incurred: " << comparisons << std::endl;

    return 0;
}
