#include "common.h"

int evalRPN(vector<string>& tokens) {
    int i = 0, opI = 0, n = tokens.size();
    std::vector<int> nums(n, 0);

    for(;i<n; i++)
    {
        const string& temp = tokens[i];
        if(isOperator(temp))
        {
            opI--;
            nums[opI-1] = doOperation(temp[0], nums[opI-1], nums[opI]);
        }
        else
        {
            nums[opI] = std::stoi(temp);
            opI++;
        }
    }
    std::cout << endl;
    return nums[0];
}

bool isOperator(const std::string& s)
{
    return s[0] < 0x30 && s.size() == 1;
}

int doOperation(const char c, int a, int b)
{
    switch(c)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b; 
        case '/':
            return a / b; 
        default:
            return 0;
    }
}