#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        if (s.empty()) return 0;

        std::vector<int> char_frequency(256, 0);
        int left = 0;
        int max_frequency = 0;
        int max_len = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            unsigned char right_char = static_cast<unsigned char>(s[right]);
            ++char_frequency[right_char];
            
            max_frequency = std::max(max_frequency, char_frequency[right_char]);

            // If replacements required > k, shift the left bound
            int current_window_size = right - left + 1;
            if (current_window_size - max_frequency > k) {
                unsigned char left_char = static_cast<unsigned char>(s[left]);
                --char_frequency[left_char];
                ++left;
            }

            max_len = std::max(max_len, right - left + 1);
        }

        return max_len;
    }
};