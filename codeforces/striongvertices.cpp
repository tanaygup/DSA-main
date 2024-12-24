#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        priority_queue<pair<int, int>> maxH;
        vector<int> ans;
        int max_diff = INT_MIN;

        // Calculate the difference a[i] - b[i] and find the maximum diff
        for (int i = 0; i < n; i++)
        {
            int diff = a[i] - b[i];
            max_diff = max(max_diff, diff); // Track the maximum difference
        }

        // Collect all indices with the maximum difference
        for (int i = 0; i < n; i++)
        {
            int diff = a[i] - b[i];
            if (diff == max_diff)
            {
                ans.push_back(i + 1); // Store 1-based index
            }
        }

        // Output the results
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}