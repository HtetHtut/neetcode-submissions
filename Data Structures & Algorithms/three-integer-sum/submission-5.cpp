#include <algorithm>
#include <vector>
#include <unordered_set>

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;

        const int size = static_cast<int>(nums.size());
        for (int i = 0; i < size - 2; ++i)
        {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int left_pointer = i + 1;
            int right_pointer = size - 1;
            while(left_pointer < right_pointer)
            {
                int sum = nums[i] + nums[left_pointer] + nums[right_pointer];
                if (sum < 0)
                {
                    ++left_pointer;
                }
                else if (sum > 0)
                {
                    --right_pointer;
                }
                else
                {
                    result.push_back({nums[i], nums[left_pointer], nums[right_pointer]});
                    ++left_pointer;
                    --right_pointer;
                    
                    while(left_pointer < right_pointer && nums[left_pointer] == nums[left_pointer-1]) ++left_pointer;
                    while(left_pointer < right_pointer && nums[right_pointer] == nums[right_pointer+1]) --right_pointer;
                }
            }
        }
        return result;
    }
};
