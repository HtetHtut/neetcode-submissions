#include <stack>
#include <string>

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> char_stack = {};

        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                char_stack.push(c);
            }
            else if (c == ')')
            {
                if (!char_stack.empty() && char_stack.top() == '(')
                {
                    char_stack.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (c == '}')
            {
                if (!char_stack.empty() && char_stack.top() == '{')
                {
                    char_stack.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (c == ']')
            {
                if (!char_stack.empty() && char_stack.top() == '[')
                {
                    char_stack.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return char_stack.empty();
    }
};
