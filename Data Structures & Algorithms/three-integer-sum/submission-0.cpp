#include <algorithm>
#include <vector>
#include <unordered_set>

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> results;
        const size_t n = nums.size();

        for (size_t i = 0; i < n; ++i)
        {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            std::unordered_set<int> seen;
            for (size_t j = i + 1; j < n; ++j)
            {
                int complement = -nums[i] - nums[j];
                if (seen.contains(complement))
                {
                    results.push_back({nums[i], complement, nums[j]});
                    while (j + 1 < n && nums[j] == nums[j + 1]) ++j;
                }
                seen.insert(nums[j]);
            }
        }
        return results;
    }
};