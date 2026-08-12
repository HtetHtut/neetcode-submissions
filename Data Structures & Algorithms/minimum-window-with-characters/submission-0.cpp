#include <string>
#include <vector>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) {
            return "";
        }

        // Frequency map for characters needed from t
        std::vector<int> target_counts(128, 0);
        int required_unique_chars{0};

        for (char c : t) {
            if (target_counts[static_cast<unsigned char>(c)] == 0) {
                ++required_unique_chars;
            }
            ++target_counts[static_cast<unsigned char>(c)];
        }

        // Frequency map for characters in the current window
        std::vector<int> window_counts(128, 0);
        
        int formed_unique_chars{0};
        int left{0};
        int min_length{INT_MAX};
        int min_left{0};

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            unsigned char right_char = static_cast<unsigned char>(s[right]);
            ++window_counts[right_char];

            // If current char count matches target char count, we met one character requirement
            if (target_counts[right_char] > 0 && window_counts[right_char] == target_counts[right_char]) {
                ++formed_unique_chars;
            }

            // Contract the window from the left while it remains valid
            while (left <= right && formed_unique_chars == required_unique_chars) {
                int current_window_size = right - left + 1;
                if (current_window_size < min_length) {
                    min_length = current_window_size;
                    min_left = left;
                }

                unsigned char left_char = static_cast<unsigned char>(s[left]);
                --window_counts[left_char];

                // If dropping left_char breaks the required frequency, decrement formed count
                if (target_counts[left_char] > 0 && window_counts[left_char] < target_counts[left_char]) {
                    --formed_unique_chars;
                }

                ++left;
            }
        }

        return min_length == INT_MAX ? "" : s.substr(min_left, min_length);
    }
};
