/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

when n = 1, solution is 1
when n = 2, solution is 2
when n = 3, solution is 3
when n = 4, solution is 5

this is the fibo sequence
*/

class Solution {
public:
    int climbStairs(int n) {
        int nMin2 = 1;
        int nMin1 = 2;
        if (n == 1)
        {
            return nMin2;
        }
        if (n == 2)
        {
            return nMin1;
        }

        for (int i = 3; i < n; i++)
        {
            int tmp = nMin2 + nMin1;
            nMin2 = nMin1;
            nMin1 = tmp;
        }

        return first+second;

    }
};