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

bool isBalanced(string s)
{
    return count(s.begin(), s.end(), ')') < count(s.begin(), s.end(), '(');
}

void backtrack(vector<string> &result, int remOpen, int remClosed, string curr, int n)
{
    if (curr.size() == 2 * n)
    {
        result.push_back(curr);
        return;
    }
    if (remOpen > 0)
    {
        curr.push_back('(');
        backtrack(result, remOpen - 1, remClosed, curr, n);
        curr.pop_back();
    }
    if (remOpen < remClosed)
    {
        curr.push_back(')');
        backtrack(result, remOpen, remClosed - 1, curr, n);
        curr.pop_back();
    }
}
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        backtrack(result, n, n, "", n);
        return result;
    }
};