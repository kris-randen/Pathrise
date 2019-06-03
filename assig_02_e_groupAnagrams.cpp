void swap(char* a, char* b)
{
    char* temp = a; a = b; b = temp;
}

string signature(const string& v)
{
    if (v.size() < 2) return v;
    
    string s = v;
    
    for (int i=0; i < s.size(); ++i)
    {
        char m = s[i];
        
        for (int j=(i+1); j < s.size(); ++j)
        {
            if (s[j] < m)
            {
                m = s[j]; swap(s[i], s[j]);
            }
        }
    }
    return s;
}

class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string> > h;
        unordered_map<string, vector<string> >::iterator t;
        
        vector<vector<string> > group;
        
        for (int i=0; i < strs.size(); ++i)
        {
            if (h.count(signature(strs[i])) == 0) h[signature(strs[i])] = {strs[i]};
            else h[signature(strs[i])].push_back(strs[i]);
        }
        
        for (t = h.begin(); t != h.end(); ++t)
        {
            group.push_back(t->second);
        }
        
        return group;
    }
};

// Runtime: 40 ms, faster than 92.60% of C++ online submissions for Group Anagrams.
// Memory Usage: 18.8 MB, less than 78.75% of C++ online submissions for Group Anagrams.