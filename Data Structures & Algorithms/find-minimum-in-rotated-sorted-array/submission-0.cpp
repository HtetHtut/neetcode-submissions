#include <algorithm>
#include <iterator>
#include <vector>

class Solution {
public:
    int findMin(std::vector<int> &nums) {
        if(nums.empty()){
            return 0;
        }

        return  *std::min_element(nums.begin(), nums.end());
    }
};
