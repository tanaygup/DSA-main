#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tt;
    cin >> tt;

    while (tt--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &i : a)
            cin >> i;

        sort(a.begin(), a.end());

        int answer = n;

        for (int i = 0; i + 1 < n; i++)
        {
            int left = i + 1, right = n - 1, index = i + 1;

            while (left <= right)
            {
                int mid = (left + right) / 2;
                if (a[i] + a[i + 1] > a[mid])
                {
                    index = mid, left = mid + 1;
                }
                else
                    right = mid - 1;
            }

            answer = min(answer, n - (index - i + 1));
        }

        cout << answer << "\n";
    }
}