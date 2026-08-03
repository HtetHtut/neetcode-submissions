#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        std::unordered_map<int, int> freq_map;
        for (int num : nums) freq_map[num]++;

        std::vector<std::vector<int>> buckets(nums.size() + 1);
        for (const auto& [number, frequency] : freq_map){
            buckets[frequency].push_back(number);
        }

        std::vector<int> results;
        for (int i = buckets.size()-1; i>=0; --i){
            for (int number : buckets[i]){
                results.push_back(number);

                if (results.size() == k) return results;
            }
        }
        return results;
    }
};
