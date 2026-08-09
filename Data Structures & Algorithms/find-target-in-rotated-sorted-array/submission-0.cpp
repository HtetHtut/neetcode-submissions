#include <algorithm>
#include <iterator>
#include <vector>

class Solution {
public:
    int search(const std::vector<int>& nums, int target) {
        if (nums.empty()) return -1;

        int first_val = nums[0];
        bool target_on_left = (target >= first_val);

        auto it = std::partition_point(nums.begin(), nums.end(), [=](int x) {
            bool x_on_left = (x >= first_val);

            if (x_on_left == target_on_left) {
                return x < target;
            }

            return x_on_left;
        });

        if (it != nums.end() && *it == target) {
            return static_cast<int>(std::distance(nums.begin(), it));
        }

        return -1;
    }
};