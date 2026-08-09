#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& heights) {
        int size = static_cast<int>(heights.size() - 1);

        int max_area = 0;
        int left_index = 0;
        int right_index = size;
        while (left_index < right_index)
        {
            int area = calculateArea(heights, left_index, right_index);
            max_area = std::max(max_area, area);

            if (heights[left_index] < heights[right_index]){
                ++left_index;
            }
            else
            {
                --right_index;
            }
        }
        return max_area;
    }
    int calculateArea(const std::vector<int>& heights, int left_index, int right_index){
        return std::min(heights[left_index], heights[right_index]) * (right_index - left_index);
    }
};
