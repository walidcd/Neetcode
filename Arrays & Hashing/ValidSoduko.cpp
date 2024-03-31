#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
using namespace std;

// time complexity O(n)
// Space Complexity O(n)

bool validLine(vector<char> v)
{
    unordered_set<char> s;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != '.')
        {
            if (s.count(v[i]) != 0)
                return false;
            s.insert(v[i]);
        }
    }
    return true;
}
bool validColumn(vector<vector<char>> v, int j)
{
    unordered_set<char> s;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i][j] != '.')
        {
            if (s.count(v[i][j]) != 0)
                return false;
            s.insert(v[i][j]);
        }
    }
    return true;
}

bool validSquare(vector<vector<char>> v, int r, int c)
{
    unordered_set<char> s;
    for (int i = r; i < r + 3; i++)
    {
        for (int j = c; j < c + 3; j++)
        {
            if (v[i][j] != '.')
            {
                if (s.count(v[i][j]) != 0)
                    return false;
                s.insert(v[i][j]);
            }
        }
    }
    return true;
}

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // check lines
        for (int i = 0; i < board.size(); i++)
            if (!validLine(board[i]))
                return false;
        // check Columns
        for (int j = 0; j < board.size(); j++)
            if (!validColumn(board, j))
                return false;
        // check Squares
        for (int i = 0; i < board.size(); i += 3)
            for (int j = 0; j < board.size(); j += 3)
                if (!validSquare(board, i, j))
                    return false;
        return true;
    }
};