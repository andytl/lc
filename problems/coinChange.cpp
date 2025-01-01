#include "problems.h"

// 322. Coin Change
// https://leetcode.com/problems/coin-change/description/
/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

Example 3:

Input: coins = [1], amount = 0
Output: 0

Constraints:
    1 <= coins.length <= 12
    1 <= coins[i] <= 2^31 - 1
    0 <= amount <= 10^4

>>>
For each number, check if change can be made using each option of coin, using the
largest coin first. If it does not work, try with the next smaller coin. Subtract the
coin from the goal, if it is 0, it takes one coin. If the remainder is still positive,
the subproblem is finding the minimum coins to make the remaining amount.

[1,2,5]
Coins_needed (CN) = [1,2,2,2,1,... CN[amount]]

Let Coins[0...C-1] be all coins available
For each n, CN[n] = 1 + min(CN[n-Couns[1]], CN[n-Couns[2]], ... CN[n-Couns[C-1]])
If CN[i] for any i <


Per leetcode, can optimize further by cutting non-coin denominations from the bottom up DP alg,
this results in a reduction of the runtime by a constant factor

*/

namespace coinChange {
    int coinChange(vector<int>& coins, int amount)
    {
        //sort(coins)
        vector<int> numberOfCoinsToMake(amount + 1, INT32_MAX);
        numberOfCoinsToMake[0] = 0;
        for (int currentAmount = 1; currentAmount <= amount; currentAmount++)
        {
            int smallestCombination = INT32_MAX;
            for (int coin = 0; coin < coins.size(); coin++)
            {
                int denomination = coins[coin];
                if (currentAmount >= denomination)
                {
                    int smallestCombinationForRemainder = numberOfCoinsToMake[currentAmount - denomination];
                    if (smallestCombinationForRemainder != INT32_MAX)
                    {
                        smallestCombination = min(smallestCombination, smallestCombinationForRemainder + 1);
                    }
                }
                // else currentAmount < denomination, int32_max as sentinel
            }
            numberOfCoinsToMake[currentAmount] = smallestCombination;
        }
        int ans = numberOfCoinsToMake[amount];
        return (ans == INT32_MAX) ? -1 : ans;
    }

    TEST(coinChange, T1) {
        vector<int> coins {1,2,5};
        EXPECT_EQ(coinChange(coins, 11), 3);
    }

    TEST(coinChange, T2) {
        vector<int> coins {2,5};
        EXPECT_EQ(coinChange(coins, 11), 4);
    }

    TEST(coinChange, T3) {
        vector<int> coins {5,10,20};
        EXPECT_EQ(coinChange(coins, 40), 2);
    }

    TEST(coinChange, T4) {
        vector<int> coins {2};
        EXPECT_EQ(coinChange(coins, 3), -1);
    }

    TEST(coinChange, T5) {
        vector<int> coins {1};
        EXPECT_EQ(coinChange(coins, 0), 0);
    }
}