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
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<pair<int, int>> st;
        st.push({temperatures[0], 0});
        int n = temperatures.size();
        vector<int> ans(n, 0);
        bool flag = false;
        for (int i = 1; i < temperatures.size(); i++)
        {
            flag = false;
            while (temperatures[i] > st.top().first)
            {
                ans[st.top().second] = i - st.top().second;
                st.pop();
                if (st.empty())
                {
                    st.push({temperatures[i], i});
                    flag = true;
                    break;
                }
            }
            if (flag)
                continue;
            st.push({temperatures[i], i});
        }
        return ans;
    }
};

// main()