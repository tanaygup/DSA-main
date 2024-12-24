#include <iostream>
#include <vector>
#include <cstring>

const int MOD = 1e9 + 7;

class Solution
{
public:
    int n, m;
    std::vector<int> nums;
    std::vector<std::vector<int>> memo;

    int countWays(int idx, int prev_val)
    {
        if (idx == n)
            return 1; // Reached the end of the array

        if (memo[idx][prev_val] != -1)
            return memo[idx][prev_val];

        int result = 0;

        // If the current value is unknown (0), try all possible values in range [1, m]
        if (nums[idx] == 0)
        {
            for (int val = 1; val <= m; ++val)
            {
                if (idx == 0 || abs(val - prev_val) <= 1)
                {
                    result = (result + countWays(idx + 1, val)) % MOD;
                }
            }
        }
        else
        {
            // If the current value is fixed, only consider that value
            if (idx == 0 || abs(nums[idx] - prev_val) <= 1)
            {
                result = (result + countWays(idx + 1, nums[idx])) % MOD;
            }
        }

        return memo[idx][prev_val] = result;
    }

    int solve(int n, int m, std::vector<int> &nums)
    {
        this->n = n;
        this->m = m;
        this->nums = nums;
        memo = std::vector<std::vector<int>>(n, std::vector<int>(m + 1, -1));

        return countWays(0, 0); // Start from index 0 with no previous value
    }
};

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
    }

    Solution sol;
    std::cout << sol.solve(n, m, nums) << std::endl;
    return 0;
}
