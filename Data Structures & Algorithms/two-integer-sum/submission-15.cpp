#include <string>
#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        for (size_t i = 0; i < nums.size(); ++i)
        {
            int target_offset = target - nums[i];
            for (size_t j = i + 1; j < nums.size(); ++j)
            {
                if (nums[j] == target_offset){
                    std::vector<int> results = {int(i), int(j)};
                    return results;
                }
            }

        }
    }
};
