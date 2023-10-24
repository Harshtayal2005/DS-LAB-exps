#include <iostream>
#include <vector>
using namespace std;

int findFloor(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int floor = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return nums[mid];
        } else if (nums[mid] < target) {
            floor = nums[mid];
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return floor;
}

int findCeil(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int ceil = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return nums[mid];
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            ceil = nums[mid];
            right = mid - 1;
        }
    }

    return ceil;
}

int findPeak(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1]) {
            return nums[mid];
        } else if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return nums[left];
}

int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return nums[left];
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 5;

    cout << "Floor: " << findFloor(nums, target) << endl;
    cout << "Ceil: " << findCeil(nums, target) << endl;
    cout << "Peak: " << findPeak(nums) << endl;
    cout << "Minimum: " << findMin(nums) << endl;

    return 0;
}
