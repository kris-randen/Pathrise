// Runtime: 4 ms, faster than 98.25% of C++ online submissions for Magical String.
// Memory Usage: 15.1 MB, less than 6.56% of C++ online submissions for Magical String.

/*
518. Coin Change 2
Medium

733

37

Favorite

Share
You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

 

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10] 
Output: 1
 

Note:

You can assume that

0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        if (coins.size() == 0) return (amount > 0) ? 0:1;
        bool b = (amount % coins[0] == 0);
        if (coins.size() == 1) return b ? 1:0;
        
        vector<vector<int> > T(coins.size(), vector<int>(amount + 1, 0));
        
        for (int i=1; i <= amount; ++i)
        {
            T[0][i] = (i % coins[0] == 0) ? 1:0 ;
        }
        
        for (int j=0; j < coins.size(); ++j)
        {
            T[j][0] = 1;
        }
        
        for (int j=1; j < coins.size(); ++j)
        {
            for (int i=1; i <= amount; ++i)
            {
                for (int k=0; k <= (i / coins[j]); ++k)
                {
                    T[j][i] += T[j-1][i - k*(coins[j])];
                }
            }
        }
        return T[coins.size()-1][amount];
    }
};

// Runtime: 140 ms, faster than 10.51% of C++ online submissions for Coin Change 2.
// Memory Usage: 19.8 MB, less than 30.42% of C++ o