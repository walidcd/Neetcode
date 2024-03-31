#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// time complexity O(n)
// Space Complexity O(n)

int operation(string a, string b, string operat)
{
    if (operat == "+")
        return (stoi(a) + stoi(b));
    if (operat == "-")
        return (stoi(b) - stoi(a));
    if (operat == "*")
        return (stoi(a) * stoi(b));
    if (operat == "/")
        return (stoi(b) / stoi(a));
    return 0;
}
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        unordered_set<string> signs;
        signs.insert("+");
        signs.insert("*");
        signs.insert("-");
        signs.insert("/");
        stack<string> st;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (signs.count(tokens[i]) == 1)
            {
                string a = st.top();
                st.pop();
                string b = st.top();
                st.pop();
                string operat = tokens[i];
                int result = operation(a, b, operat);
                st.push(to_string(result));
                continue;
            }
            st.push(tokens[i]);
        }
        return stoi(st.top());
    }
};