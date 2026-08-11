#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s){
        if(s.empty()) return 0;

        std::vector<int> last_seen(256, -1);
        int max_length{0};
        int left{0};

        for(int right = 0; right < static_cast<int>(s.size()); ++right){
            unsigned char c = s[right];

            if(last_seen[c] >= left){
                left = last_seen[c] + 1;
            }
            last_seen[c] = right;
            max_length = std::max(max_length, right - left + 1);
        }
        return max_length;
    }
};
