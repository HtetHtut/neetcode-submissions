#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    std::string encode(std::vector<std::string> &strs)
    {
        std::string encoded_string;

        for (const auto &string : strs)
        {
            encoded_string.append(":");
            encoded_string.append(std::to_string(string.size()));
            encoded_string.append(";");
            encoded_string.append(string);
        }
        return encoded_string;
    }

    std::vector<std::string> decode(std::string s)
    {
        std::vector<std::string> decoded_string_vector;

        for (size_t i = 0; i < s.length(); ++i)
        {
            int string_length = 0;
            if (s[i] == ':')
            {
                int j = i + 1;
                while (s[j] != ';'){
                    char what_j = s[j];
                    ++j;
                }
                std::string substring = s.substr(i+1, j-1);
                string_length = std::stoi(substring);
                std::string temp_string = s.substr(j+1, string_length);
                i += j+string_length-i;
                decoded_string_vector.push_back(temp_string);
            }
        }
        return decoded_string_vector;
    }
};
