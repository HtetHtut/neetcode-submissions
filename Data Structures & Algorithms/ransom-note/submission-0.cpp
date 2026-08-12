#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        if(magazine.empty() || (ransomNote.size() > magazine.size())) return false;

        std::vector<int> char_counts(256, 0);
        for(const char c : magazine){
            char_counts[static_cast<unsigned char>(c)]++;
        }
        for(const char c : ransomNote){
            if (--char_counts[static_cast<unsigned char>(c)] < 0) return false;
        }
        return true;
    }
};
