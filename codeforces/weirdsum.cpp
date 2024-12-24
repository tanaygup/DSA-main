#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    int maxi = 0;
    unordered_map<int, vector<pair<int, int>>> mp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            mp[grid[i][j]].push_back({i, j});
            maxi = max(maxi, grid[i][j]);
        }
    }

    ll sum = 0;

    for (int i = 1; i <= maxi; i++)
    {
        if (mp[i].size() < 2)
            continue;

        vector<ll> x, y;

        for (int j = 0; j < mp[i].size(); j++)
        {
            x.push_back(mp[i][j].first);
            y.push_back(mp[i][j].second);
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        ll x_sum = 0;
        int n = x.size();

        for (int j = 0; j < n; j++)
            x_sum += x[j];

        for (int j = 0; j < n; j++)
        {
            x_sum -= x[j];
            sum += (x_sum - (n - 1 - j) * x[j]);
        }

        ll y_sum = 0;
        for (int j = 0; j < n; j++)
            y_sum += y[j];

        for (int j = 0; j < n; j++)
        {
            y_sum -= y[j];
            sum += (y_sum - (n - 1 - j) * y[j]);
        }
    }

    cout << sum << endl;
    return 0;
}
