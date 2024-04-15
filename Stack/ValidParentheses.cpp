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

class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, char> m;
        m['('] = ')';
        m['['] = ']';
        m['{'] = '}';
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < s.size(); i++)
        {
            if (st.size() == 0)
            {
                st.push(s[i]);
                continue;
            }
            if (s[i] == m[st.top()])
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};