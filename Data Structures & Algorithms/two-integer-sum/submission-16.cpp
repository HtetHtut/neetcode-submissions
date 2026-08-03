#include <unordered_map>
#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> map;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            int target_offset = target - nums[i];
            if (map.contains(target_offset)){
                return {map[target_offset], int(i)};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};
