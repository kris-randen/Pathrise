/*
73. Set Matrix Zeroes
Medium

1024

190

Favorite

Share
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int> >& m) 
    {
        unordered_set<int> rows;
        unordered_set<int> cols;
        unordered_set<int>::iterator t;
        
        for (int i=0; i < m.size(); ++i)
        {
            for (int j=0; j < m[0].size(); ++j)
            {
                cout << "i = " << i << " j = " << j << " m = " << m[i][j] << endl;
                if (m[i][j] == 0)
                {
                    rows.insert(i); cols.insert(j);   
                }
            }
        }
        
        for (t=rows.begin(); t!=rows.end(); ++t)
        {
            for (int j=0; j < m[0].size(); ++j)
            {
                m[*t][j] = 0;
            }
        }
        
        for (t=cols.begin(); t!=cols.end(); ++t)
        {
            for (int i=0; i < m.size(); ++i)
            {
                m[i][*t] = 0;
            }
        }
    }
};

// Runtime: 88 ms, faster than 10.12% of C++ online submissions for Set Matrix Zeroes.
// Memory Usage: 11.9 MB, less than 5.10% of C++ online submissions for Set Matrix Zeroes.
