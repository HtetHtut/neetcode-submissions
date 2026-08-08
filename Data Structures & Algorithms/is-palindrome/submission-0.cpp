#include <algorithm>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        std::erase_if(s, [](unsigned char c) {
            return !std::isalnum(c);
        });
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){
            return std::tolower(c);
        });
        std::string cleaned_string = s;
        std::string reversed_string(cleaned_string.rbegin(), cleaned_string.rend());

        if (reversed_string == cleaned_string){
            return true;
        }
        return false;
    }
};
