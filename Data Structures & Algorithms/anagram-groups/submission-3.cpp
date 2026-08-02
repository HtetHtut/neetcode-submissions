#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        // So basically I need to find each anagram, then if I have a list of that anagram type,
        // I need to push the unsorted word into the right list
        // so I will create a list of sorted string to the list of anagrams
        // then I will just return the values, which should be lists, as a list

        std::unordered_map<std::string, std::vector<std::string>> anagram_map;
        std::vector<std::string> sorted_strings;
        for (std::string og_string : strs) {
            std::string sorted_string = og_string;
            std::sort(sorted_string.begin(), sorted_string.end());
            

            if (anagram_map.contains(sorted_string)){
                anagram_map[sorted_string].push_back(og_string);
            }
            else{
                std::vector<std::string> og_string_vec = {og_string};
                anagram_map[sorted_string] = og_string_vec;
            }
        }
        std::vector<std::vector<std::string>> results;
        for (auto [sorted_string, string_vec] : anagram_map){
            results.push_back(string_vec);
        }
        return results;
    }
};
