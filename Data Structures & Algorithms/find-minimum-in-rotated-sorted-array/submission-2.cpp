#include <algorithm>
#include <iterator>
#include <vector>

class Solution {
public:
    int findMin(std::vector<int> &nums) {
        if(nums.empty()) return 0;

        auto min_it = std::partition_point(nums.begin(), nums.end(), [last = nums.back()](int x){
            return x > last;
        });

        return *min_it;
    }
};
