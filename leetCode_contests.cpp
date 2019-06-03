/*
1048. Longest String Chain
User Accepted: 522
User Tried: 719
Total Accepted: 525
Total Submissions: 1267
Difficulty: Medium
Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

 

Example 1:

Input: ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: one of the longest word chain is "a","ba","bda","bdca".
 

Note:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of English lowercase letters.
*/

typedef string& String;
typedef const String Cstring;
typedef unordered_set<char, int> CharSignature;
typedef unordered_set<int, vector<string> > WordSignature;

struct node
{
    string s;
    node* previous, next;
    node(string s)
    {
        this->s = s;
        previous = NULL; next = NULL;
    }
};



CharSignature signatureOfWord(Cstring s)
{
    CharSignature h;
    
    for (int i=0; i<s.size(); ++i)
    {
        if (h.count(s[i]) == 0) 
            h[s[i]] = 1;
        else 
            h[s[i]]++;
    }
    return h;
}

int compareSignature()

bool isSuccessor(Cstring p, Cstring s)
{
    if (s.size() != p.size() + 1) return false;
    
}

class Solution {
public:
    int longestStrChain(vector<string>& words) 
    {
        WordSignature h;
        
        for (int i=0; i<words.size(); ++i)
        {
            if (h.count(words[i].size()) == 0) 
                h[words[i].size()] = {words[i]};
            else 
                h[words[i].size()].push_back(words[i]);
        }
        
        
    }
};