/*
266. Palindrome Permutation
Easy

192

39

Favorite

Share
Given a string, determine if a permutation of the string could form a palindrome.

Example 1:

Input: "code"
Output: false
Example 2:

Input: "aab"
Output: true
Example 3:

Input: "carerac"
Output: true
*/

class Solution {
public:
    bool canPermutePalindrome(string s) 
    {
        unordered_map<char, int> h;
        unordered_map<char, int>::iterator t;
        
        for (int i=0; i < s.size(); ++i)
        {
            if (h.count(s[i]) == 0) h[s[i]] = 1;
            else h.erase(s[i]);
        }
        
        int numEvenChars, numOddChars;
        numEvenChars = numOddChars = 0;
        
        for (t=h.begin(); t!=h.end(); ++t)
        {
            if (t->second % 2 == 0) numEvenChars++;
            else 
            {
                if (s.size() % 2 == 0) return false;
                numOddChars++;
                if (numOddChars > 1) return false; 
            }
        }
        return true;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Palindrome Permutation.
// Memory Usage: 8.6 MB, less than 5.22% of C++ online submissions for Palindrome Permutation.

