#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int dp[1000][100000];

int multiply(int a, int b, int c)
{
    int ans = 0;
    while (b)
    {
        if (b & 1)
            ans = ans + a, ans %= c;
        a += a;
        a %= c;
        b /= 2;
    }
    return ans;
}

int helper(int i, vector<int> &pr, vector<int> &pa, int x)
{

    int n = pr.size();
    if (i >= n)
        return 0;
    if (dp[i][x] != -1)
        return dp[i][x];
    int take = 0;

    if (x - pr[i] >= 0)
    {
        take = pa[i] + helper(i + 1, pr, pa, x - pr[i]);
    }

    int nottake = helper(i + 1, pr, pa, x);

    return dp[i][x] = max(take, nottake);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;

    vector<int> pr(n), pa(n);
    for (int i = 0; i < n; i++)
        cin >> pr[i];
    for (int i = 0; i < n; i++)
        cin >> pa[i];

    // memset(dp, -1, sizeof(dp));

    // cout << helper(0, pr, pa, x);
    vector<int> dp(x+1,0);
}