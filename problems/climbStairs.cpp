#include "problems.h"

namespace climbStairs {
    // 70. Climbing Stairs
    // https://leetcode.com/problems/climbing-stairs/description/
    /*
    You are climbing a staircase. It takes n steps to reach the top.
    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

    n=1 1
    n=2 2 ([n-1=1](1) + [n-2=0](0)) 1,1/2
    n=3 3 ([n-1=2](2) + [n-2=1](1)) 1,1,1/1,2/2,1
    n=4 5 ([n-1=3](3) + [n-2=2](2)) 1,1,1,1/1,2,1/1,1,2/2,1,1/2,2

    m[1] = 1
    m[2] = 2
    m[n] = m[n-1] + m[n-2] for n > 2
    */
    int climbStairs(int n) {
        if (n <= 2)
        {
            return n;
        }
        int nMinus2 = 1;
        int nMinus1 = 2;
        int nCur = 0;
        for (int i = n - 2; i > 0; i--)
        {
            nCur = nMinus1 + nMinus2;
            nMinus2 = nMinus1;
            nMinus1 = nCur;
        }
        return nCur;
    }

    TEST(climbStairs, FirstBaseCase) {
        EXPECT_EQ(climbStairs(1), 1);
    }

    TEST(climbStairs, SecondBaseCase) {
        EXPECT_EQ(climbStairs(1), 1);
    }

    TEST(climbStairs, FourIteration) {
        EXPECT_EQ(climbStairs(4), 5);
    }
}