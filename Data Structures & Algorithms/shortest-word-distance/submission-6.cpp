#include <algorithm>
#include <climits>
#include <string>
#include <iostream>
#include <vector>

class Solution {
public:
    int shortestDistance(std::vector<std::string>& wordsDict, std::string word1, std::string word2) {
        int word1index{-1};
        int word2index{-1};
        int shortest_length{INT_MAX};

        for(int i = 0; i < static_cast<int>(wordsDict.size()); ++i){
            if(wordsDict[i] == word1){
                word1index = i;
            }

            if(wordsDict[i] == word2){
                word2index = i;
            }

            if((word1index!=-1) && (word2index!=-1)){
                if(word1index > word2index){
                    shortest_length = std::min(shortest_length, word1index-word2index);
                }
                else{
                    shortest_length = std::min(shortest_length, word2index-word1index);
                }
            }
        }
        return shortest_length;
    }
};